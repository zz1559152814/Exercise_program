#include<stdio.h>

int fibonacci(n);

void main(void)
{
    int n;
    printf("input the number:");
    scanf("%d",&n);
    printf("Fibonacci(%d) is %d",n,fibonacci(n));
    getch();
}

int fibonacci(int n)
{
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}
