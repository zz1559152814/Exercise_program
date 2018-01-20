#include<stdio.h>

void main(void)
{
    int a,b,c;
    while(c!=-1)
    {
        puts("enter sales in dollars:");
        scanf("%d",&a);
        b=200+a*0.09;
        printf("Salary is:$%d\n",b);
    }

}
