#include<stdio.h>

void main(void)
{
    int counter,x;
    printf("A\tA+2\tA+4\tA+6");
    counter=1;
    x=1;
    while(x<=5)
    {
        printf("\n%d\t%d\t%d\t%d",3*x,3*x+2,3*x+4,3*x+6);
        ++x;
    }
    getch();
}
