#include<stdio.h>
int max(int x,int y)
{
    int a;
    if(x>y) a=x;
    else a=y;
    return(a);
}
void main(void)
{
    int max(int x,int y);
    int a,b,c;
    printf("please intput two numbers:");
    scanf("\n%d%d",&b,&c);
    a=max(b,c);
    if(c==b)
    {
        printf("\nthe two number is ");
    }
    else
    {
        printf("\n%d",a);
    }
}







