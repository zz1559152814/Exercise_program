#include<stdio.h>

void main(void)
{
    int x=0;
    int y=0;
    y=x+++1,++x+2;
    printf("\ny=%d,x=%d",y,x);
}
