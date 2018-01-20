
void liwenlinposition(double Handle_X,double Handle_Y)
{
	struct Point Handle;
	Handle.x=Handle_X*0.25;
	Handle.y=Handle_Y*0.25;

	lwl_goline(GPS.position,Handle);
}
void lwl_goline(struct Point real_point,struct Point aim_point)
{
	static double aim_r;
	int Length;
	double line_angle;
	double error_angle,error_dis_y,error_dis_x;
	double Vout_A,Vout_D_x,Vout_D_y,v_err_x,v_err_y,v_err_y_temp,v_err_x_temp;
	double Speed_X,Speed_Y,Speed_Rotation;
	static int count_lwl;
	static struct Point aim_temp_point;
	double speed_x,speed_y;

	speed_x=(aim_point.x-aim_temp_point.x)*rate;
	speed_y=(aim_point.y-aim_temp_point.y)*rate;

	if(count_lwl==0)
		aim_r=MISO_GPS_ANG.f64_data;

/********get error information**********/
		error_angle = aim_r-GPS.radian;

		if(error_angle>pi)
			error_angle-=2*pi;
		if(error_angle<-pi)
			error_angle+=2*pi;

		if(fabs(error_angle)<=0.8*3.1415926/180)
			error_angle=0;
		if(fabs(error_dis_x)<=15)
			error_dis_x=0;
		if(fabs(error_dis_y)<=15)
			error_dis_y=0;

	error_dis_y=aim_point.y-real_point.y;
	error_dis_x=aim_point.x-real_point.x;

	Vout_D_x = DistancePID(error_dis_x,pid_goline_D);
	Vout_D_y = DistancePID(error_dis_y,pid_goline_D);
	Vout_A = 1000*AnglePID(error_angle,pid_goline_A);

	v_err_x = Vout_D_x;
	v_err_y = Vout_D_y;

  if(count_lwl==0)
	{
		v_err_x_temp=v_err_x;
		v_err_y_temp=v_err_y;
	}

	Speed_X = speed_x+v_err_x;
	Speed_Y = speed_y+v_err_y;
	Speed_Rotation=Vout_A;
	SetSpeed(Speed_X,Speed_Y,Speed_Rotation);

	aim_temp_point=aim_point;
	++count_lwl;
	if(count_lwl==4)
	count_lwl=1;
}

void lwlgoline_pid_set(void)
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

void lwlgoline_rate_set(void)
{
    static struct Input_ListValue Values[]=
    {
        {&rate,	TYPE_FP64,	"dis.p"},
    };

    LCD_Clear();
    GPS_Clear();
    PID_Clear();

    Input_List(Values,1);

    if(rt_mb_recv(&Mb_Key, &key_value, RT_WAITING_FOREVER) == RT_EOK);
}
