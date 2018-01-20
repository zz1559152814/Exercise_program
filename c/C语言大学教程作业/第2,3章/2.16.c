#include<stdio.h>

void main(void)
{
    int x;
    int y,q,w,e,r,t;
    printf("please intput two numbers:");
    scanf("\n%d%d",&x,&y);
    q=x+y;
    w=x-y;
    e=x*y;
    r=x/y;
    t=x%y;
    printf("\n%d %d %d %d %d",q,w,e,r,t);
}
