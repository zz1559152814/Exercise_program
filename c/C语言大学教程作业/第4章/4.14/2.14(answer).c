#include<stdio.h>

void main(void)
{
    int n,number,factorial;
    for(n=1;n<=5;n++)
    {
        factorial=1;
        for(number=1;number<=n;number++)
        {
            factorial*=number;
        }
        printf("%d\t%d\n",n,factorial);
    }
    return 0;
}
s
