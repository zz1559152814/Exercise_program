#include<stdio.h>

void main(void)
{
    int n,counter,space;
    for(n=1; n<=10; n++)
    {
        for(space=1; space<n; space++)
        {
            printf("  ");
        }
        for(counter=10-space;counter>=0;counter--)
            printf("* ");
        printf("\n");
    }
    getch(0);
}
