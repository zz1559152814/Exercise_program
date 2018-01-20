/****************************goline*******************************/
void my_goline(double *Speed_X,double *Speed_Y,double *Speed_Rotation)
{
	static double aim_r;
	static int count=0,n;
	static double error_dis,error_angle;         //´íÎóÐÅÏ¢
	double Vout_A;
	double Vout_D;                       //pidÏµÊý
	double v_err_x,v_err_y;                             //¾­¹ýµ÷ÕûµÄÎó²îËÙ¶È
	static  double line_angle;
	static struct Point aim_pos,temp_aim_pos,real_pos;
	/*****************ÏóÏÞµÄÈ·¶¨******************/
	int up_down;                            //ÅÐ¶Ï³µµÄÄ¿±êÔË¶¯·½ÏòÊÇÏòÉÏ»¹ÊÇÏòÏÂÓÃÀ´½øÐÐÏóÏÞµÄÈ·¶¨
	int right_left;

	Get_Solpe_of_Vout_D(real_pos,aim_pos,temp_aim_pos,&right_left,&up_down);
	/*****get really pos**********/
	real_pos.x=GPS.position.x;
	real_pos.y=GPS.position.y;
  /*****get aim_pos*****/
	if(count==0)
	{
		aim_r=GPS.radian;
		aim_pos=real_pos;
	}
	aim_pos.x+=*Speed_X*0.005;
	aim_pos.y+=*Speed_Y*0.005;


/********get error information**********/
		error_angle = aim_r-GPS.radian;

		if(error_angle>pi)
			error_angle-=2*pi;
		if(error_angle<-pi)
			error_angle+=2*pi;

		if(n==1)
		{
			error_dis=GetDis_P2L_PP(real_pos,temp_aim_pos,aim_pos);

			/******************line_angle*******************/

			if(aim_pos.x-temp_aim_pos.x==0)
				line_angle=1.5707;
			else
				if(aim_pos.y-temp_aim_pos.y>=0)
				{
					if((aim_pos.y-temp_aim_pos.y)/(aim_pos.x-temp_aim_pos.x)>=0)
						line_angle=atan(aim_pos.y-temp_aim_pos.y)/(aim_pos.x-temp_aim_pos.x);
					else
						line_angle=atan(aim_pos.y-temp_aim_pos.y)/(aim_pos.x-temp_aim_pos.x)+PI;
				}
				else
				{
					if((aim_pos.y-temp_aim_pos.y)/(aim_pos.x-temp_aim_pos.x)<0)
						line_angle=2*PI-atan(aim_pos.y-temp_aim_pos.y)/(aim_pos.x-temp_aim_pos.x);
					else
						line_angle=atan(aim_pos.y-temp_aim_pos.y)/(aim_pos.x-temp_aim_pos.x)+PI;
				}

			temp_aim_pos=aim_pos;
		}
/*********get ajustment data**************/
		if(fabs(error_angle)<=0.8*0.08723)
			error_angle=0;
		if(fabs(error_dis)<=10)
			error_dis=0;                       //¿ªÆôÈÝ´í

		Vout_A = 1000*AnglePID(error_angle,pid_goline_A);
		Vout_D = DistancePID(error_dis,pid_goline_D);

		if(up_down*right_left==1)
		{
			v_err_x = -Vout_D*sin(line_angle);
			v_err_y =  Vout_D*cos(line_angle);
		}
		else if(up_down*right_left==-1)
		{
			v_err_x = Vout_D*sin(line_angle);
			v_err_y = -Vout_D*cos(line_angle);
		}
		else
		{
			v_err_x=v_err_y=0;
		}

/**********ajust***********/
		*Speed_X = *Speed_X+v_err_x;
		*Speed_Y = *Speed_Y+v_err_y;
		*Speed_Rotation=Vout_A;
		SetSpeed(*Speed_X,*Speed_Y,*Speed_Rotation);


/***************************/

		n%=20;
		++n;

		if(count==2)
			count=1;
		++count;
}

void pid_set_A(void)
{
    static struct Input_ListValue Values[]=
    {
        {&pid_goline_A.p,	TYPE_FP64,	"angle.p"},
        {&pid_goline_A.i,	TYPE_FP64,	"angle.i"},
				{&pid_goline_A.d, TYPE_FP64,	"angle.d"},

    };

    LCD_Clear();
    GPS_Clear();
    PID_Clear();

    Input_List(Values,3);

    if(rt_mb_recv(&Mb_Key, &key_value, RT_WAITING_FOREVER) == RT_EOK);
}

void pid_set_D(void)
{
    static struct Input_ListValue Values[]=
    {
        {&pid_goline_D.p,	TYPE_FP64,	"dis.p"},
        {&pid_goline_D.i,	TYPE_FP64,	"dis.i"},
				{&pid_goline_D.d, TYPE_FP64,	"dis.d"},

    };

    LCD_Clear();
    GPS_Clear();
    PID_Clear();

    Input_List(Values,3);

    if(rt_mb_recv(&Mb_Key, &key_value, RT_WAITING_FOREVER) == RT_EOK);
}


/*
 * º¯ÊýÃû: Get_right_left_P_p1p2
 * Ãè  Êö: ÅÐ¶ÏÏòÁ¿ËùÔÚÏóÏÞ
 * Êä  Èë: -p  µã
 *		   -p1  -p2 Ö±ÏßÉÏÒ»µã
				y=ax+b

 * Êä  ³ö: 0,1
 * µ÷  ÓÃ: Íâ²¿µ÷ÓÃ
 */
void Get_Solpe_of_Vout_D(struct Point p,struct Point p1_aim,struct Point p2,int *right_left,int *up_down)
{
	double a,b,x;
	a=GetLineSlope(p1_aim,p2);
	b=p1_aim.y-a*p1_aim.x;
	if(a!=0)
	{
		x=(p.y-b)/a;
		if(x-p.x<0)
			*right_left=-1;
		else if(x-p.x>0)
			*right_left=1;
		else
			*right_left=0;
	}
	else
	if(p1_aim.y-p2.y!=0)
	{
		if(p1_aim.y-p2.y>0)
			*up_down=1;
		else if(p1_aim.y-p2.y<0)
			*up_down=-1;
		else
			*up_down=0;
	}
}
