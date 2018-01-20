#include<stdio.h>

void main(void)
{
    int n,counter;
    for(n=10; n>=1; n--)
    {
        for(counter=1; counter<=n; counter++)
        {
            printf("* ");
        }
        printf("\n");
    }
    getch(0);
}
