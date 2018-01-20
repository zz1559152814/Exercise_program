#include "includes.h"
#include "math.h"
#define SQR 1.41421356
#include "speed_test.h"
#include "mecanum.h"
static	rt_uint32_t key_value;
int speed_x_t(void);
int speed_y_t(void);
int speed_xy_t(void);

void SetSpeed(double speed_x,double speed_y,double speed_rotation);
void Spe_Acc_get(double *acc,double *speed_really);
void acc_set(void);
float absolute(float n);
static int gotime=0;

static int n=0;
static int m=0;
static double yiqi[5][2]= {0};
static double speed[4]= {0};
static double acc[4]= {0};

static double acc_vaule_x;
static double acc_vaule_y;

FIL t_acc_y;
FIL t_acc_x;
FIL t_acc_xy;
FIL t_acc_xy;
FIL t_spe_y;
FIL t_spe_x;
FIL t_spe_xy;
FIL position_x;
FIL position_y;
FIL position_xy;
/************************²âxÖá·½ÏòµÄ×î´óËÙ¶È***************************/

void test_speed_x(void)
{
    int flag=1;
    double speed_really;
    double acceleration;

    acc_set();

    f_open (&t_acc_x, "test_acc_x.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
    f_open (&t_spe_x, "test_speed_x.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
    f_open (&position_x, "position_x.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);

    while(flag)
    {
        Speed_X=speed_really+acc_vaule_x;

        SetSpeed(Speed_X,0,0);

        Delay_ms(5);
        gotime+=5;
        Spe_Acc_get(&speed_really,&acceleration);

        SD_Printf_MQ(&t_spe_x,"%d     %f     %d     %f\r\n",gotime,speed_really,gotime,Speed_X);
        SD_Printf_MQ(&t_acc_x,"%d     %f\r\n",gotime,acceleration);
        SD_Printf_MQ(&position_x,"%f      %f       %d\r\n",GPS.position.x,GPS.position.y,gotime);

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
        LCD_WriteDouble(GPS.radian);

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
        LCD_WriteDouble(speed_really);

    }
    SD_Printf_MQ(&t_spe_x,"THE END");
    SD_Printf_MQ(&t_acc_x,"THE END");
    SD_Printf_MQ(&position_x,"THE END");

}

/************************²âyÖá·½ÏòµÄ×î´óËÙ¶È***************************/
void test_speed_y(void)
{
    int flag=1;
    double speed_really;
    double acceleration;

    acc_set();

    f_open (&t_acc_y, "test_acc_y.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
    f_open (&t_spe_y, "test_speed_y.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
    f_open (&position_y, "position_y.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
    while(flag)
    {
        Speed_Y=speed_really+acc_vaule_y;

        SetSpeed(0,Speed_Y,0);

        Delay_ms(5);
        gotime+=5;

        Spe_Acc_get(&speed_really,&acceleration);

        SD_Printf_MQ(&t_spe_y,"%d    %f    %d  %f\r\n",gotime,speed_really,gotime,Speed_Y);
        SD_Printf_MQ(&t_acc_y,"%d    %f\r\n",gotime,acceleration);
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
        LCD_WriteDouble(GPS.radian);

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
        LCD_WriteDouble(speed_really);

    }
    SD_Printf_MQ(&t_spe_y,"THE END");
    SD_Printf_MQ(&t_acc_y,"THE END");
    SD_Printf_MQ(&position_y,"THE END");

}

/***************************Ð±²â45¶È**********************************/
void test_speed_xy(void)
{
    int flag=1;
    double speed_really;
    double acceleration;
    double Speed_Angle;
    double Speed_XY;
    acc_set();

    Speed_Angle=atan(acc_vaule_y/acc_vaule_x);

    f_open (&t_acc_xy, "test_acc_xy.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
    f_open (&t_spe_xy, "test_speed_xy.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);
    f_open (&position_xy, "position_xy.txt", FA_CREATE_ALWAYS | FA_READ | FA_WRITE);

    SD_Printf_MQ(&t_acc_xy,"x        y\r\n");
    SD_Printf_MQ(&position_xy,"x            y           time\r\n");
    SD_Printf_MQ(&t_spe_xy,"x1     y1             x2       y2\r\n");
    while(flag)
    {
//			Speed_X=cos(Speed_Angle)*speed_really+acc_vaule_x;
//			Speed_Y=sin(Speed_Angle)*speed_really+acc_vaule_y;

//			Speed_XY=sqrt((Speed_X*Speed_X)+(Speed_Y*Speed_Y));
        Speed_X=acc_vaule_x;
        Speed_Y=acc_vaule_y;

        SetSpeed(Speed_X,Speed_Y,0);

        Delay_ms(5);
        gotime+=5;

        Spe_Acc_get(&speed_really,&acceleration);

        SD_Printf_MQ(&t_spe_xy,"%d    %f    %d  %f\r\n",gotime,speed_really,gotime,Speed_X==0?Speed_Y:Speed_X);
        SD_Printf_MQ(&t_acc_xy,"%d    %f\r\n",gotime,acceleration);
        SD_Printf_MQ(&position_xy,"%d    %d     %f\r\n",GPS.position.x,GPS.position.y,gotime);

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
        LCD_WriteDouble(GPS.radian);

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
        LCD_WriteDouble(Speed_X==0? Speed_Y:Speed_X);

        LCD_SetXY(0,5);
        LCD_WriteString("6.speed_really:");
        LCD_WriteDouble(speed_really);

    }
    SD_Printf_MQ(&t_spe_xy,"THE END");
    SD_Printf_MQ(&t_acc_xy,"THE END");
    SD_Printf_MQ(&position_xy,"THE END");

}

void acc_set(void)
{
    static struct Input_ListValue Values[]=
    {
        {&acc_vaule_x,	TYPE_FP64,	"acc_x"},
        {&acc_vaule_y,	TYPE_FP64,	"acc_y"},
    };

    LCD_Clear();
    GPS_Clear();
    PID_Clear();

    Input_List(Values,2);

    if(rt_mb_recv(&Mb_Key, &key_value, RT_WAITING_FOREVER) == RT_EOK);

}
void Spe_Acc_get(double *speed_really,double *acceleration)
{
//		n=n%4;
    yiqi[n%5][0]=MISO_GPS_X.f64_data;
    yiqi[n%5][1]=MISO_GPS_Y.f64_data;

    //»ñÈ¡×ø±ê
    if(m>=4)
    {
        //Í¨¹ý×ø±êËãËÙ¶ÈÓë¼ÓËÙ¶È
        speed[n%5]=sqrt((yiqi[(n-1)%5][0]-yiqi[n%5][0])*(yiqi[(n-1)%5][0]-yiqi[n%5][0])+(yiqi[n%5][1]-yiqi[(n-1)%5][1])*(yiqi[n%5][1]-yiqi[(n-1)%5][1]))/0.005;
        acc[n%5]=(speed[n%5]-speed[(n-2)%5])/2;
        //³ýÔï
        if(absolute(speed[n%5]-speed[(n-1)%5])>=200)
        {
            speed[n%5]=speed[(n-1)%5]+absolute(speed[(n-1)%5]-speed[(n-2)%5]);
        }

        //ËãµÃÆ½¾ùÊµ¼ÊËÙ¶È
        *speed_really=(speed[n%5]+speed[(n-1)%5]+speed[(n-2)%5])/3;

        *acceleration=(acc[n%5]+acc[(n-1)%5])/2;
    }
    n++;
    m++;
}
float absolute(float n)
{
    if(n<0)
        return -n;
}

//		if(m>4)
//		{
//				if(n!=0)
//				{
//						speed[n]=sqrt((yiqi[n-1][0]-yiqi[n][0])*(yiqi[n-1][0]-yiqi[n][0])+(yiqi[n][1]-yiqi[n-1][1])*(yiqi[n][1]-yiqi[n-1][1]))/0.005;
//
//				}
//				else
//						speed[0]=sqrt((yiqi[4][0]-yiqi[0][0])*(yiqi[4][0]-yiqi[0][0])+(yiqi[4][1]-yiqi[0][1])*(yiqi[4][1]-yiqi[0][1]))/0.005;


//		if(n==0)
//		{
//			*speed_really=(speed[3]+speed[0])/2;
//			acc[0]=speed[0]-speed[3];
//		}
//
//		else if(n==1)
//		{
//			*speed_really=(speed[1]+speed[0])/2;
//			acc[1]=speed[1]-speed[0];
//		}
//		else  if(n==2)
//		{
//			*speed_really=(speed[2]+speed[1])/2;
//			acc[2]=speed[2]-speed[1];
//		}

//		else if(n==3)
//		{
//			*speed_really=(speed[3]+speed[2])/2;
//			acc[3]=(speed[3]-speed[2]);
//		}
//

//»ñÈ¡Êµ¼ÊËÙ¶ÈµÄÆ½¾ùÖµºÍÊµ¼Ê¼ÓËÙ¶È
//    if(n%5!=0)
//		{
//				*acceleration=(acc[0]+acc[3])/2;
//		}
//		else
//				*acceleration=(acc[n]+acc[n-1])/2;

