#include<stdio.h>

void main(void)
{
    int counter,number,largest;
    scanf("%d",&counter);
    largest=0;
    while(counter>0)
    {
        scanf("%d",&number);
        if(number>=largest)
            largest=number;
        counter--;
    }
    printf("%d",largest);
    return 0;

}
