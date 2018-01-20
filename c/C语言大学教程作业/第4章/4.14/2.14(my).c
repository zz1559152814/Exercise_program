#include<stdio.h>

void main(void)
{
    int n,counter,factorial;
    printf("n  1 2 3 4 5\n");
    printf("n! ");
    for(counter=1; counter<=5; counter++)
    {
        factorial=1;
        n=counter;
        while(n>0)
        {
            factorial*=n;
            n--;
        }
        printf("%d ",factorial);
    }
}

