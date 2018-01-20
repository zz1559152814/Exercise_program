#include<stdio.h>

int diviser(int a,int b);

void main(void)
{
    int a;
    int b;
    printf( "Enter two numbers between 1 and 9999: " );
    scanf("%d   %d",&a,&b);
    printf("The number with its digits reversed is: %d",diviser(a,b));
    getch();
}

int diviser(int a,int b)
{
    int small,n,diviser=0;
    small=(a<b?a:b);
    for(n=1;n<=small;n++)
    {
        if(a%n==0&&b%n==0)
        {
            if(diviser<=n)
                diviser=n;
        }
    }
    return diviser;
}
