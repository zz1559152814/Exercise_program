#include<stdio.h>

#define pi 3.14159
void main(void)
{
    float a,b,c,d;
    printf("\nintput the number:");
    scanf("%f",&a);
    b=2*pi*a;
    c=2*a;
    d=pi*a*a;
    printf("\n%f\n%f\n%f`",b,c,d);
}
