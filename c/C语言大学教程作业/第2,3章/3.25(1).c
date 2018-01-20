#include<stdio.h>

void main(void)
{
    printf("N\t10*N\t100*N\t1000*N\n");
    int b;

    b=1;

    while(b<=10)
    {
        printf("%d\t%d\t%d\t%d\t\n",b,10*b,100*b,1000*b);
        b=b+1;

    }
}
