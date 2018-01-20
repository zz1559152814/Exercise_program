#include<stdio.h>

int prefect(int number);
int inter(double number);

void main()
{
    int counter;
    for(counter=2 ; counter<=100000; counter++)
    {
        if(prefect(counter))
            printf("%d\n",counter);
    }
}
int prefect(int number)
{
    int n;
    int add=1;
    for(n=2; n<number/2; n++)
    {
        if(number%n==0)
        {
            add+=n;
            add+=number/n;
        }
    }
    if(add==number)
        return 1;
    else
        return 0;
}
int inter(double number)
{
    if((int)number==number)
        return 1;
    else
        return 0;
}
