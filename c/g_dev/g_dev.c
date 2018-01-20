#include<stdio.h>
#include<math.h>

int main(void)
{
    static double x[8];
    static double mean;
    static double st_dev;
    static double sum;
    static double sum_sqr;
    int i;
    printf("intput the number of the arry:");
    for(i=0; i<8; i++)
    {
        scanf("%lf",&x[i]);
    }
    for(i=0; i<8; i++)
    {
        sum+=x[i];
        sum_sqr=x[i]*x[i];
    }
    mean=sum/8;
    printf("Index             Item            Difference\n");
    for(i=0; i<8; i++)
    {
        printf("%-16d %-16lf %-20lf\n",i,x[i],x[i]-mean);
    }
    return(0);
}
