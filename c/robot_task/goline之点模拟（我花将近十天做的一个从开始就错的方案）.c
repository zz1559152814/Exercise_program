void my_goline(double *Speed_X,double *Speed_Y,double *Speed_Rotation)
{
	static double aim_x,aim_y,aim_r;
	static int count,n;
  double real_x,real_y;
	double error_dis_x,error_dis_y,error_angle;
	double Vout_A=0;
	double Vout_D_x=0,Vout_D_y=0;
	double line_angle;
	double v_err_x,v_err_y;

	/*****get really pos**********/
	real_x=MISO_GPS_X.f64_data;
	real_y=MISO_GPS_Y.f64_data;


/*****get aim_pos*****/
	aim_x+=*Speed_X*0.005;
	aim_y+=*Speed_Y*0.005;

	if(count==0)
		aim_r=MISO_GPS_ANG.f64_data;

/********get error information**********/
	n%=10;
	if(n==0)
	{
		error_angle = aim_r-GPS.radian;

		if(error_angle>pi)
			error_angle-=2*pi;
		if(error_angle<-pi)
			error_angle+=2*pi;

		error_dis_x=aim_x-real_x;
		error_dis_y=aim_y-real_y;
/*********get ajustment data**************/
		line_angle=atan(*Speed_Y / *Speed_X);
		Vout_A = 1000*AnglePID(error_angle,pid_goline_A);
		Vout_D_x = DistancePID(error_dis_x,pid_goline_D);
		Vout_D_x = DistancePID(error_dis_x,pid_goline_D);

		v_err_x = -Vout_D_x;
		v_err_y =  Vout_D_y;
/**********ajust***********/
		*Speed_X += v_err_x;
		*Speed_Y += v_err_y;
		*Speed_Rotation=Vout_A;
		SetSpeed(*Speed_X,*Speed_Y,*Speed_Rotation);

		SetSpeed(*Speed_X,*Speed_Y,*Speed_Rotation);
	}
		++count;
		++n;

}
