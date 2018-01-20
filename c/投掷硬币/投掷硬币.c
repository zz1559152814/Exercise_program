#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int tails(void);

void main(void)
{
    int n,counter;
    int coin[2]= {0};
    srand( time( NULL ) );
    for(n=1; n<=100; n++)
    {
        coin[tails()]+=1;
        printf("%d   ",tails());
    }
    printf("\nHeads times:%d\nTails times:%d",coin[0],coin[1]);
}

int tails(void)
{
    if(rand()%2==0)
        return 0;
    else
        return 1;
}
//srand( time( NULL ) );不能放在循环里面
