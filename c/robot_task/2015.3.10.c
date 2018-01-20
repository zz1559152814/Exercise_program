//	static double aim_r;
//	int Length;
//	double line_angle;
//	double error_angle,error_dis_y,error_dis_x;
//	double Vout_A,Vout_D_x,Vout_D_y,v_err_x,v_err_y,v_err_y_temp,v_err_x_temp;
//	double Speed_X,Speed_Y,Speed_Rotation;
//	static int count_lwl;
//	static struct Point aim_temp_point;


//	if(count_lwl==0)
//		aim_r=MISO_GPS_ANG.f64_data;
//	if(on_off==0)
//		aim_point=real_point;
//	else
//		aim_point=aim_point;
///********get error information**********/
//		error_angle = aim_r-GPS.radian;

//		if(error_angle>pi)
//			error_angle-=2*pi;
//		if(error_angle<-pi)
//			error_angle+=2*pi;

//		if(fabs(error_angle)<=0.8*3.1415926/180)
//			error_angle=0;
//		if(fabs(error_dis_x)<=15)
//			error_dis_x=0;
//		if(fabs(error_dis_y)<=15)
//			error_dis_y=0;

//	error_dis_y=aim_point.y-real_point.y;
//	error_dis_x=aim_point.x-real_point.x;

//	if(fabs(error_dis_x)<=20)
//		error_dis_x=0;
//	if(fabs(error_dis_y)<=20)
//		error_dis_y=0;
//
//	Vout_D_x = DistancePID(error_dis_x,pid_goline_D_x);
//	Vout_D_y = DistancePID(error_dis_y,pid_goline_D_x);
//	Vout_A = 1000*AnglePID(error_angle,pid_goline_A);

//	v_err_x = Vout_D_x;
//	v_err_y = Vout_D_y;

//  if(count_lwl==0)
//	{
//		v_err_x_temp=v_err_x;
//		v_err_y_temp=v_err_y;
//	}

//	Speed_X = v_err_x;
//	Speed_Y = v_err_y;
//	Speed_Rotation=Vout_A;
//	SetSpeed(Speed_X,Speed_Y,Speed_Rotation);

//	aim_temp_point=aim_point;
//	++count_lwl;
//	if(count_lwl==4)
//	count_lwl=1;
