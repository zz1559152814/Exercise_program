#include<stdio.h>
void main(void)
{
    int z,x,c;
    z=1;
    x=2;
    c=3;

    if(z<x)
        {z=c;
        x=z;
        c=x;}
        printf("\n%d,%d,%d",z,x,c);

}
