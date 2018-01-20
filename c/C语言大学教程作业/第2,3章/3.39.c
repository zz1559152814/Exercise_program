#include<stdio.h>

void main(void)
{
    int number,counter,dividend,digit,counter2,counter3;
    scanf("%d",&number);
    counter=1;
    dividend=10;
    counter2=1;
    counter3=0;
    while(number/dividend>=1)         /*???????ÎªÊ²Ã´ÊÇ>=*/
    {
        dividend*=10;
        ++counter;
    }
    printf("%d\n",counter);
    while(counter>0)
    {
        digit=((number-number%counter2)/counter2)%10;
        if(digit%7==0)
            ++counter3;
        counter2*=10;
        counter--;
    }
    printf("%d",counter3);
}
