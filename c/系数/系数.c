#include<stdio.h>
#include<math.h>

#define PI 3.141592654

void main(void)
{
	float C11, C12, C21, C22;
	float C11_1, C11_2, C12_1, C12_2, C21_1, C21_2, C22_1, C22_2;
	float angle_a, angle_b;
	float angle_a1, angle_a2, angle_b1, angle_b2;
	float N[8];
	int i;
	FILE *fp;
	int length=3000;
	for (i = 0; i < 8; i++)
	{
		printf("please input ");
		printf("%d\n", i+1);
		scanf("%f", &N[i]);
	}
	if (N[0]<0)
	{
		N[0] = -N[0];
		N[1] = -N[1];
		N[4] = -N[4];
		N[5] = -N[5];
	//	Encoders[0].dir = -Encoders[0].dir;
	}

	if (N[6]<0)
	{
		N[2] = -N[2];
		N[3] = -N[3];
		N[6] = -N[6];
		N[7] = -N[7];
		//Encoders[0].dir = -Encoders[1].dir;
	}

	switch ((int)(N[4] / fabs(N[4])))
	{
	case -1:
		angle_a1 = atan(-N[4] / N[0]);
		angle_a2 = atan(-N[5] / N[1]);
		angle_a = (angle_a1 + angle_a2) / 2;
		C11_1 = length* cos(angle_a) / N[0];
		C11_2 = -length* sin(angle_a) / N[4];
		C11 = (C11_1 + C11_2) / 2;
		C12_1 = -length * cos(angle_a) / N[1];
		C12_2 = length * sin(angle_a) / N[5];
		C12 = (C12_1 + C12_2) / 2;
		break;
	case 1:
		angle_a1 = atan(N[5] / N[0]);
		angle_a2 = atan(N[4] / N[1]);
		angle_a = (angle_a1 + angle_a2) / 2;
		C11_1 = length * cos(angle_a) / N[0];
		C11_2 = length * sin(angle_a) / N[5];
		C11 = (C11_1 + C11_2) / 2;
		C12_1 = -length * cos(angle_a) / N[1];
		C12_2 = -length * sin(angle_a) / N[4];
		C12 = (C12_1 + C12_2) / 2;
		break;
	}

	switch ((int)(N[2] / fabs(N[2])))
	{
	case 1:
		angle_b1 = atan(N[6] / N[2]);
		angle_b2 = atan(N[7] / N[3]);
		angle_b = (angle_b1 + angle_b2) / 2;
		C21_1 = length * sin(angle_b) / N[6];
		C21_2 = length* cos(angle_b) / N[2];
		C21 = (C21_1 + C21_2) / 2;
		C22_1 = -length* sin(angle_b) / N[7];
		C22_2 = -length* cos(angle_b) / N[3];
		C22 = (C22_1 + C22_2) / 2;
		break;
	case -1:
		angle_b1 = atan(-N[6] / N[3]) + PI;
		angle_b2 = atan(-N[7] / N[2]) + PI;
		angle_b = (angle_b1 + angle_b2) / 2;
		C21_1 = length* sin(angle_b) / N[6];
		C21_2 = -length* cos(angle_b) / N[3];
		C21 = (C21_1 + C21_2) / 2;
		C22_1 = -length * sin(angle_b) / N[7];
		C22_2 = length* cos(angle_b) / N[2];
		C22 = (C22_1 + C22_2) / 2;
		break;
	}
	printf("%f\n %f\n %f \n%f \n%f\n %f\n ", angle_a, angle_b, C11, C12, C21, C22);
	fp=fopen("data.txt","w");
	fprintf(fp,"%f %f %f %f %f %f ", angle_a, angle_b, C11, C12, C21, C22);
    fclose(fp);
}
/***************************************************************************************************
     +y    -y    +x    -x
E1   N[0]  N[1]  N[4]  N[5]
E2   N[2]  N[3]  N[6]  N[7]
****************************************************************************************************/
 /*   -26682  26755   26686  -26682
      25835  -25982    27090 -27297
*/
