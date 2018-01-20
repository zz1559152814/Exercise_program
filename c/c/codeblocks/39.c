#include<stdio.h>

void main(void)
{
    int x=1;
    int y;
    int z;
    y=++x;
    z=x++;
    printf("%d %d",y,z);
}
