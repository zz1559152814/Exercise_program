#include<stdio.h>
#include<conio.h>
void main(void)
{
    int a=5,b=4;
    printf("\n%d,%d",(a=2*8,a/4));
    a=2*8,a/4;
    printf("\n%d",a);
    printf("\n%d",a==b);
}
