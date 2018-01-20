#include<stdio.h>

int factorial(int n);

void main(void)
{
    int n;
    printf("input the number you want :");
    scanf("%d",&n);
    n=factorial(n);
    printf("the factorial of n is :%d",n);
}

int factorial(int n)
{
    printf("%d*%d\n",n,n-1);
    if(n==1)
        return 1;
    else
    {
        return factorial(n-1)*n;
    }
}
