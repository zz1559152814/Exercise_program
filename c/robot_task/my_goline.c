#include "includes.h"
#include "math.h"
#define SQR 1.41421356
#define PI 3.1415926
#include "speed_test.h"
#include "mecanum.h"
static	rt_uint32_t key_value;

void acc_set(void);
void my_goline(double *Speed_X,double *Speed_Y,double *Speed_Rotation);
void flag_set(void);
static double acc_vaule_x;
static double acc_vaule_y;
static int fan_time;
int GOLINEFLAG;
int delay_time;
FIL t_dis_y;
FIL t_dis_x;
FIL t_dis_xy;
FIL t_dis_aver;
FIL t_spe_y;
FIL t_spe_x;
FIL t_spe_xy;
FIL t_spe_aver;
FIL position_x;
FIL position_y;
FIL position_xy;


/************************goline**********************************/
struct PID pid_goline_A={4,800000,0};
struct PID pid_goline_D_x={4,1000000,0};
struct PID pid_goline_D_y={4,1000000,0};
double keepspeed1=2;
double keepspeed=150;
int pid_rate=1;
/************************²âxÖá·½ÏòµÄ×î´óËÙ¶È***************************/

void test_speed_x(void)
{
		int gotime=0;
//		int fan=0;
    int flag=1;
    acc_set();
		flag_set();
    f_open (&t_spe_x, "test_speed_x.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
    f_open (&position_x, "position_x.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
		f_open (&t_dis_x, "original_x.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);

    while(flag)
    {
        Delay_ms(5);
        gotime+=5;


				Speed_X=realspe+acc_vaule_x;
				Speed_Y=0;
				Speed_Rotation=0;

//			if(gotime==5)
//					FanAccelepid_rate(0,0);

//			if(gotime<=fan_time)
//				{
//					if(gotime<=3000)
//						fan=gotime/100;
//					else
//						fan=30;
					SetSpeed(Speed_X,0,0);
//					FanAccelepid_rate(fan,0);
//				}
//				else
//				{
//					SetSpeed(0,0,0);
//					FanAccelepid_rate(0,0);
//				}
				if(GOLINEFLAG)
					my_goline(&Speed_X,&Speed_Y,&Speed_Rotation);

        SD_Printf_MQ(&t_spe_x,"%d     %f     %d     %f\r\n",gotime,realspe,gotime,Speed_X);
        SD_Printf_MQ(&position_x,"%f      %f       %d\r\n",GPS.position.x,GPS.position.y,gotime);
				SD_Printf_MQ(&t_dis_x,"%f      %f        %f\r\n",MISO_GYRO_RAD.f64_data,MISO_ENC1_DIS.f64_data,MISO_ENC2_DIS.f64_data);

        if(rt_mb_recv(&Mb_Key, &key_value, RT_WAITING_NO) == RT_EOK)
        {
            switch(key_value)
            {
            case key4:
                flag=0;
                break;
            }
        }


        LCD_Clear();
        LCD_SetXY(0,0);
        LCD_WriteString("1.A:");
        LCD_WriteDouble(MOSI_GPS_ANG.f64_data);

        LCD_SetXY(0,1);
        LCD_WriteString("2.X:");
        LCD_WriteDouble(GPS.position.x);

        LCD_SetXY(0,2);
        LCD_WriteString("3.Y:");
        LCD_WriteDouble(GPS.position.y);

        LCD_SetXY(0,3);
        LCD_WriteString("4.STOP");

        LCD_SetXY(0,4);
        LCD_WriteString("5.speed_set:");
        LCD_WriteDouble(Speed_X);

        LCD_SetXY(0,5);
        LCD_WriteString("6.speed_really:");
        LCD_WriteDouble(realspe);

    }
    SD_Printf_MQ(&t_spe_x,"THE END");
    SD_Printf_MQ(&position_x,"THE END");
    SD_Printf_MQ(&t_dis_x,"THE END");
		gotime=0;
}

/************************²âyÖá·½ÏòµÄ×î´óËÙ¶È***************************/
void test_speed_y(void)
{
    int flag=1;
		int gotime=0;
//		int fan;
    acc_set();
		flag_set();
    f_open (&t_spe_y, "test_speed_y.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
    f_open (&position_y, "position_y.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
    f_open (&t_dis_x, "original_y.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
    while(flag)
    {
				Delay_ms(5);
        gotime+=5;

				Speed_Y=realspe+acc_vaule_y;
				Speed_X=0;
				Speed_Rotation=0;


//				if(gotime<=fan_time)
//				{
//					if(gotime<=3000)
//						fan=gotime/100;
//					else
//						fan=30;
					SetSpeed(0,Speed_Y,0);
//					FanAccelepid_rate(0,fan);
//				}
//				else
//				{
//					SetSpeed(0,0,0);
//					FanAccelepid_rate(0,0);
//				}
				if(GOLINEFLAG)
					my_goline(&Speed_X,&Speed_Y,&Speed_Rotation);

				SD_Printf_MQ(&t_spe_y,"%d    %f    %d  %f\r\n",gotime,realspe,gotime,Speed_Y);
				SD_Printf_MQ(&t_dis_x,"%f      %f        %f\r\n",MISO_GYRO_RAD.f64_data,MISO_ENC1_DIS.f64_data,MISO_ENC2_DIS.f64_data);
        SD_Printf_MQ(&position_y,"%d    %d     %f\r\n",GPS.position.x,GPS.position.y,gotime);


        if(rt_mb_recv(&Mb_Key, &key_value, RT_WAITING_NO) == RT_EOK)
        {
            switch(key_value)
            {
            case key4:
                flag=0;
                break;
            }
        }


        LCD_Clear();
        LCD_SetXY(0,0);
        LCD_WriteString("1.A:");
        LCD_WriteDouble(MOSI_GPS_ANG.f64_data);

        LCD_SetXY(0,1);
        LCD_WriteString("2.X:");
        LCD_WriteDouble(GPS.position.x);

        LCD_SetXY(0,2);
        LCD_WriteString("3.Y:");
        LCD_WriteDouble(GPS.position.y);

        LCD_SetXY(0,3);
        LCD_WriteString("4.STOP");

        LCD_SetXY(0,4);
        LCD_WriteString("5.speed_set:");
        LCD_WriteDouble(Speed_Y);

        LCD_SetXY(0,5);
        LCD_WriteString("6.speed_really:");
        LCD_WriteDouble(realspe);

    }
    SD_Printf_MQ(&t_spe_y,"THE END");
    SD_Printf_MQ(&position_y,"THE END");
    SD_Printf_MQ(&t_dis_x,"THE END");
		gotime=0;
}

/***************************Ð±²â45¶È**********************************/
void test_speed_xy(void)
{
    static int flag_speed=1;
		int gotime=0;
//		int fan;
		acc_set();
		flag_set();
    f_open (&t_spe_xy, "test_speed_xy.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
		f_open (&t_dis_xy, "original_xy.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);

    while(flag_speed)
    {
				Speed_Y=realspe/1.414+acc_vaule_y;
				Speed_X=realspe/1.414+acc_vaule_x;
				Speed_Rotation=0;


//				if(gotime<=fan_time)
//				{
//					if(gotime<=3000)
//						fan=gotime/100;
//					else
//						fan=30;
					SetSpeed(Speed_X,Speed_Y,0);
//					FanAccelepid_rate(fan/1.414,fan/1.414);
//				}
//				else
//				{
//					SetSpeed(0,0,0);
//					FanAccelepid_rate(0,0);
//				}
				if(GOLINEFLAG)
					my_goline(&Speed_X,&Speed_Y,&Speed_Rotation);

      SD_Printf_MQ(&t_spe_xy,"%d     %f     %d     %f\r\n",gotime,realspe,gotime,Speed_X*1.4142);
			SD_Printf_MQ(&t_dis_x,"%f        %f        %f\r\n",MISO_GYRO_RAD.f64_data,MISO_ENC1_DIS.f64_data,MISO_ENC2_DIS.f64_data);

			if(rt_mb_recv(&Mb_Key, &key_value, RT_WAITING_NO) == RT_EOK)
        {
					switch(key_value)
            {
            case key4:
							flag_speed=0;
						break;
            }
        }

        LCD_Clear();
        LCD_SetXY(0,0);
        LCD_WriteString("1.A:");
        LCD_WriteDouble(MOSI_GPS_ANG.f64_data);

        LCD_SetXY(0,1);
        LCD_WriteString("2.Speed_X:");
        LCD_WriteDouble(Speed_X);

        LCD_SetXY(0,2);
        LCD_WriteString("3.Speed_Y:");
        LCD_WriteDouble(Speed_Y);

        LCD_SetXY(0,3);
        LCD_WriteString("4.STOP");

        LCD_SetXY(0,4);
        LCD_WriteString("5.speed_set:");
        LCD_WriteDouble(acc_vaule_x==0? acc_vaule_y:acc_vaule_x);

        LCD_SetXY(0,5);
        LCD_WriteString("6.speed_really:");
        LCD_WriteDouble(realspe);

    }
		SetSpeed(0,0,0);
    SD_Printf_MQ(&t_spe_xy,"THE END");
		SD_Printf_MQ(&t_dis_x,"THE END");
		gotime=0;
}
void aver_go(void)
{
    static int flag=1;
		int gotime=0;
		acc_set();
	  flag_set();
    f_open (&t_spe_aver, "test_speed_aver.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
		f_open (&t_dis_aver, "original_aver.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);

    while(flag)
    {
			Delay_ms(5);
        gotime+=5;

				Speed_Y=acc_vaule_y;
				Speed_X=acc_vaule_x;
				Speed_Rotation=0;

  			SetSpeed(Speed_X,Speed_Y,0);

			if(GOLINEFLAG)
					my_goline(&Speed_X,&Speed_Y,&Speed_Rotation);

				SD_Printf_MQ(&t_spe_aver,"%d    %f    %d  %f\r\n",gotime,realspe,gotime,Speed_Y);
        SD_Printf_MQ(&t_dis_aver,"%d    %d     %f\r\n",GPS.position.x,GPS.position.y,gotime);


        if(rt_mb_recv(&Mb_Key, &key_value, RT_WAITING_NO) == RT_EOK)
        {
            switch(key_value)
            {
            case key4:
                flag=0;
                break;
						case key7:
								pid_set_A();
								break;
						case key8:
								pid_set_D_y();
								break;
            }
        }


        LCD_Clear();
        LCD_SetXY(0,0);
        LCD_WriteString("1.A:");
        LCD_WriteDouble(MOSI_GPS_ANG.f64_data);

        LCD_SetXY(0,1);
        LCD_WriteString("2.X:");
        LCD_WriteDouble(GPS.position.x);

        LCD_SetXY(0,2);
        LCD_WriteString("3.Y:");
        LCD_WriteDouble(GPS.position.y);

        LCD_SetXY(0,3);
        LCD_WriteString("4.STOP");

        LCD_SetXY(0,4);
        LCD_WriteString("5.speed_set:");
        LCD_WriteDouble(Speed_Y);

        LCD_SetXY(0,5);
        LCD_WriteString("6.speed_really:");
        LCD_WriteDouble(realspe);

        LCD_SetXY(0,7);
        LCD_WriteString("7.pid_a:");

				LCD_SetXY(0,8);
        LCD_WriteString("8.pid_d:");

    }
		SD_Printf_MQ(&t_spe_aver,"THE END");
		SD_Printf_MQ(&t_dis_aver,"THE END");
		gotime=0;
}

void acc_set(void)
{
    static struct Input_ListValue Values[]=
    {
        {&acc_vaule_x,	TYPE_FP64,	"acc_x"},
        {&acc_vaule_y,	TYPE_FP64,	"acc_y"},
				{&fan_time,   	TYPE_INT16,	"fan_time"},

    };

    LCD_Clear();
    GPS_Clear();
    PID_Clear();

    Input_List(Values,3);

    if(rt_mb_recv(&Mb_Key, &key_value, RT_WAITING_FOREVER) == RT_EOK);
}
void flag_set(void)
{
    static struct Input_ListValue Values[]=
    {
        {&GOLINEFLAG,	TYPE_INT8,	"GOLINEFLAG"},

    };

    LCD_Clear();
    GPS_Clear();
    PID_Clear();

    Input_List(Values,1);

    if(rt_mb_recv(&Mb_Key, &key_value, RT_WAITING_FOREVER) == RT_EOK);
}



void my_goline(double *Speed_X,double *Speed_Y,double *Speed_Rotation)
{
	static double aim_x,aim_y,aim_r;
	static int count;
	double error_dis_x,error_dis_y,error_angle;         //´íÎóÐÅÏ¢
	double Vout_A=0;
	double Vout_D_x=0,Vout_D_y=0;                       //pidÏµÊý
	double v_err_x,v_err_y;                             //¾­¹ýµ÷ÕûµÄÎó²îËÙ¶È
	double temp_speed_x,temp_speed_y;                             //
	static int x_off,y_off;
	static int xoff_flag,yoff_flag;
	static int only_x_goline,only_y_goline;

	temp_speed_x=*Speed_X;
	temp_speed_y=*Speed_Y;

	/*****ÅÐ¶Ïxon xoff yon yoff*****/
	if(*Speed_X==0)
	{
		if(xoff_flag!=0)
		{
			xoff_flag=0;
			x_off=0;
		}
		x_off++;
	}
	else
		xoff_flag=1;

	if(*Speed_Y==0)
	{
		if(yoff_flag!=0)
		{
			yoff_flag=0;
			y_off=0;
		}
		y_off++;
	}
	else
		yoff_flag=1;

/*************Ê¹ÓÃÉÏÒ»´Îº¯ÊýÔËÐÐµÃµ½µÄonly_x_goline£¬only_x_goline½øÐÐÎó²î¼ÆËã,
	Õâ´Î¼ÆËã²¢²»ÊÇÍêÈ«ÕýÈ·£¬Ö»ÔÚX,YÁ½¸ö·½Ïò¶¼¶¯µÄÇé¿öÏÂÊÇ´íÎóµÄ´íÎó»áÔÚÏÂÃæ¾ÀÕý***************/
	if(only_x_goline&&only_y_goline)
	{
		aim_x=GPS.position.x;
		aim_y=GPS.position.y;
	}
	else if(only_y_goline&&only_x_goline!=0)
	{
		aim_y=GPS.position.y;
		aim_x=aim_x;
	}
	else if(only_x_goline&&only_y_goline!=0)
	{
		aim_x=GPS.position.x;
		aim_y=aim_y;
	}
	else if(only_x_goline==0&&only_y_goline==0)
	{
		aim_x=GPS.position.x;
		aim_y=GPS.position.y;
	}


/**********************ÅÐ¶Ï´Ë´ÎÔË¶¯µÄÔË¶¯×´Ì¬£¬×÷ÎªÏÂ´ÎÖ´ÐÐ´Ëº¯ÊýµÄÒÀ¾Ý£¬Í¬Ê±Ò²ÅÅ³ýÁËXY¶¼¶¯µÄÇé¿öÏÂÉÏÃæËã·¨µÄ´íÎó***********/
	if(*Speed_X==0)
	{
		if(*Speed_Y !=0)
			only_y_goline=1;
		else if(y_off<=500)
			only_y_goline=1;
		else
			only_y_goline=0;
	}
	else
		aim_x=GPS.position.x;

	if(*Speed_Y==0)
	{
		if(*Speed_X!=0)
			only_x_goline=1;
		else if(x_off<=500)
			only_x_goline=1;
		else
			only_x_goline=0;
	}
	else
		aim_y=GPS.position.y;


	if(count==0)
		aim_r=MISO_GPS_ANG.f64_data;

/********get error information**********/
		error_angle = aim_r-GPS.radian;

		if(error_angle>pi)
			error_angle-=2*pi;
		if(error_angle<-pi)
			error_angle+=2*pi;

		error_dis_x=aim_x-GPS.position.x;
		error_dis_y=aim_y-GPS.position.y;
/*********ÈÝ´í**************/

		if(fabs(error_angle)<=0.8*3.1415926/180)
			error_angle=0;
		if(fabs(error_dis_x)<=15)
			error_dis_x=0;
		if(fabs(error_dis_y)<=15)
			error_dis_y=0;
/********Ê¹¸³ËÙÍ¼Ïñ³ÊÏÖÈçÏÂ×´Ì¬****************/
		if(fabs(error_dis_x)<=keepspeed&&error_dis_x!=0)
			error_dis_x*=keepspeed1;
		if(fabs(error_dis_y)<=keepspeed&&error_dis_y!=0)
			error_dis_y*=keepspeed1;

		if(error_dis_x<=keepspeed*keepspeed1&&error_dis_x>=keepspeed)
			error_dis_x=keepspeed*keepspeed1;
		if(error_dis_y<=keepspeed*keepspeed1&&error_dis_y>=keepspeed)
			error_dis_y=keepspeed*keepspeed1;

		Vout_A = 1000*AnglePID(error_angle,pid_goline_A);
		Vout_D_x = DistancePID(error_dis_x,pid_goline_D_y);
		Vout_D_y = DistancePID(error_dis_y,pid_goline_D_y);

		v_err_x = Vout_D_x;
		v_err_y = Vout_D_y;
/******************ajust****************/
		*Speed_X += v_err_x;
		*Speed_Y += v_err_y;
		*Speed_Rotation=Vout_A;
/**************¸ù¾ÝÔË¶¯×´Ì¬µ÷½Ú********************/
		if(only_y_goline&&only_x_goline)
		{
			SetSpeed(temp_speed_y,temp_speed_y,*Speed_Rotation);
			LCD_SetXY(0,7);
			LCD_WriteString("1:");
			LCD_WriteDouble(v_err_y);
		}
		else if(only_x_goline&&only_y_goline!=0)
		{
			SetSpeed(temp_speed_x,*Speed_Y,*Speed_Rotation);
			LCD_SetXY(0,7);
			LCD_WriteString("2:");
			LCD_WriteDouble(v_err_y);
		}

		else if(only_y_goline&&only_x_goline!=0)
		{
			SetSpeed(*Speed_X,temp_speed_y,*Speed_Rotation);
			LCD_SetXY(0,7);
			LCD_WriteString("3:");
			LCD_WriteDouble(v_err_y);
		}

		else if(only_x_goline==0&&only_y_goline==0)
		{
			SetSpeed(temp_speed_y,temp_speed_y,*Speed_Rotation);
		  LCD_SetXY(0,7);
			LCD_WriteString("4:");
			LCD_WriteDouble(v_err_y);
		}


/***************************/
		++count;
		if(count==4)
			count=1;

		LCD_SetXY(0,4);
    LCD_WriteString("Speed_X:");
    LCD_WriteDouble(temp_speed_x);

		LCD_SetXY(0,5);
    LCD_WriteString("v_err_x:");
    LCD_WriteDouble(v_err_x);

		LCD_SetXY(0,6);
		LCD_WriteString("Speed_Y");
    LCD_WriteDouble(*Speed_Y);


}
void pid_set_A(void)
{
    static struct Input_ListValue Values[]=
    {
        {&pid_goline_A.p,	TYPE_FP64,	"angle.p"},
        {&keepspeed1,	TYPE_FP64,	"keepspeed1"},
				{&keepspeed, TYPE_FP64,	"keepspeed"},

    };

    LCD_Clear();
    GPS_Clear();
    PID_Clear();

    Input_List(Values,3);

    if(rt_mb_recv(&Mb_Key, &key_value, RT_WAITING_FOREVER) == RT_EOK);
}

void pid_set_D_y(void)
{
    static struct Input_ListValue Values[]=
    {
        {&pid_goline_D_y.p,	TYPE_FP64,	"dis.p"},
        {&pid_goline_D_y.i,	TYPE_FP64,	"dis.i"},
				{&pid_goline_D_y.d, TYPE_FP64,	"dis.d"},

    };

    LCD_Clear();
    GPS_Clear();
    PID_Clear();

    Input_List(Values,3);

    if(rt_mb_recv(&Mb_Key, &key_value, RT_WAITING_FOREVER) == RT_EOK);

	}

void pid_set_D_x(void)
{
    static struct Input_ListValue Values[]=
    {
        {&pid_goline_D_x.p,	TYPE_FP64,	"dis.p"},
        {&pid_goline_D_x.i,	TYPE_FP64,	"dis.i"},
				{&pid_goline_D_x.d, TYPE_FP64,	"dis.d"},

    };

    LCD_Clear();
    GPS_Clear();
    PID_Clear();

    Input_List(Values,3);

    if(rt_mb_recv(&Mb_Key, &key_value, RT_WAITING_FOREVER) == RT_EOK);
}
