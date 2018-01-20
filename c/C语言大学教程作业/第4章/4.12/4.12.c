#include<stdio.h>

void main(void)
{
    int number,total;
    total=0;
    for(number=2;number<=30;number+=2)
        total+=number;
        printf("%d",total);
}

