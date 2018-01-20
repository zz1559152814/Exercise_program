#include<stdio.h>

void main(void)
{
    int number,product;
    scanf("%d",&number);
    product=1;
    while(number>0)
    {
        product=product*number;
        number--;
    }
    printf("%d",product);
}
