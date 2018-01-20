#include<stdio.h>

void main(void)
{
    int w,e,a;
    a=1;
    e=1;
    w=((a-a%e)/e)%10;
    printf("%d",w);
}
