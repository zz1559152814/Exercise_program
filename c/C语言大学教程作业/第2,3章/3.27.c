#include<stdio.h>

void main(void)
{
    int number,counter,largest,second;
    counter=1;
    printf("input the number:");
    scanf("%d",&number);
    largest=number;
    printf("\nintput the number:");
    scanf("%d",&number);
    if(number>largest)
    {
        second=largest;
        largest=number;
    }
    else
        second=number;
    while(counter<=8)
    {
        printf("\nintput the number:");
        scanf("%d",&number);
        if(number>largest)
        {
            second=largest;
            largest=number;
        }
        else if(number<=largest&&number>second)
        {
            second=number;
        }
        ++counter;
    }
    printf("%d,%d",largest,second);

}
