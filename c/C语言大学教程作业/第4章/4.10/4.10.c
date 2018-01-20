#include<stdio.h>

void main(void)
{
    int number,total,counter;
    float average;
    total=0;
    counter=0;
    scanf("%d",&number);
    while(number!=9999)
    {
        total+=number;
        counter++;
        scanf("%d",&number);
    }
    if(counter==0)
        return(0);
    average=total/counter;
    printf("%f",average);
}
