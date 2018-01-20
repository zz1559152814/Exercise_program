#include<stdio.h>

void main(void)
{
    int counter,x;
    printf("N\t10*N\t100*N\t1000*N");
    counter=1;
    x=1;
    while(x<=10)
    {
        printf("\n%d\t%d\t%d\t%d",x,10*x,100*x,1000*x);
        ++x;
    }
}
