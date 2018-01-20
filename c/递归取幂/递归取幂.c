#include<stdio.h>

int pow(int base,int exponent);
void main(void)
{
   int base,exponent;
    printf("please input base and exponent:");
    scanf("%d  %d",&base, &exponent);
    printf("pow(base,exponent)=%d",pow(base,exponent));
}

int pow(int base,int exponent)
{
    if(exponent==1)
    {
        return base;
    }
    else
        return base*pow(base,exponent-1);
}
