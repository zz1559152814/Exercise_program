#include<stdio.h>

void main(void)
{
    int a,b;
    a=1;
    b=1;
    while(a<0)
    {
        a=a*b;
        b=b*2;
        printf("%d\n",a);
    }
}
