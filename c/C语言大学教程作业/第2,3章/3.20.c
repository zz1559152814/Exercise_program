#include<stdio.h>

void main(void)
{
    float a,b,c,d,e;
    while(a!=-1)
    {
        printf("enter the principal:");
        scanf("%f",&a);
        if(a==-1)
            break;
        printf("\nenter the rate:");
        scanf("%f",&b);
        printf("\nemter the day:");
        scanf("%f",&c);
        e=a*b*c/365;
        printf("\noutput the interest:%f",e);
    }
}
