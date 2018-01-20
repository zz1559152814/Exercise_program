#include<stdio.h>

void main(void)
{
    int a,b,c;
    b=0;
    c=0;
    while(c<10)
    {
        printf("enter the number:");
        scanf("%d",&a);
        if(a>b)
        {

            b=a;
        }
        else
        {

            b=b;
        }
        ++c;
    }
    printf("%d",b);
}
