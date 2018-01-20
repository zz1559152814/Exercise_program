#include<stdio.h>

void main(void)
{
    int counter;
    counter=1;
    while(counter<=10)
    {
        printf("%d\n",counter%2?11111:22222);
        ++counter;
    }
    getch();
}
