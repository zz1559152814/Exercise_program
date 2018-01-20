#include<stdio.h>
#include<time.h>
#define DIS 100

void delay(int number);

void main(void)
{
    int i;
    int rabbit=0,tortoise=0,pro;
    srand(time(NULL));
    pro=rand()%10;
    if(pro==1||pro==2)
    {
        tortoise+=3;
    }
    else if(pro==3||pro==4)
    {
        tortoise+=3;
        rabbit+=9;
    }
    else if(pro==5)
    {
        tortoise+=3;
        rabbit-=12;
    }
    else if(pro==6||pro==7)
    {
        tortoise-=6;
        rabbit+=1;
    }
    else if(pro==8)
    {
        tortoise+=1;
        rabbit+=1;
    }
    else if(pro==9||pro==10)
    {
        tortoise+=1;
        rabbit+=2;
    }
    if(rabbit<0)
        rabbit=0;
    if(tortoise<=0)
        tortoise=0;
    for(i=0;i<=DIS-1;i++)
    {
        delay(10000000);
        if(i==rabbit)
            printf("R");
        else
            printf(" ");
        printf("\n");
        if(i==tortoise)
            printf("T");
        else
            printf(" ");
        printf("\f");
    }
}
void delay(int number)
{
    int i;
    int m;
    for(i=0;i<=number;i++)
    {
        m++;
    }
}
