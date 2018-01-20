#include<stdio.h>

void main(void)
{
    int two,ten,n,yushu,x;
    scanf("%d",&ten);
    x=ten/decimal(n,ten);
    while(yushu!=0)
    {

        yushu=ten%decimal(n,x);
        x=yushu/decimal(n,x);
        if(x=1)
            printf("1");
        else
            printf("0");

    }
}
int decimal(int n,int counter1)
{
    n=0;
    if(counter1>=pow(2,n))
    {
        n++;
    }
    n=n-1;
    return n;
}
