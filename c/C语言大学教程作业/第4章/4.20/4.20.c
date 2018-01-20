#include<stdio.h>

void main(void)
{
    int produce,total,counter,price,counter2;
    total=0;

    while(produce!=-1)
    {
        scanf("%d%d",&produce,&counter);
        switch(produce)
        {
        case 1:
            total+=1*counter;
            break;
        case 2:
            total+=2*counter;
            break;
        case 3:
            total+=3*counter;
            break;
        case 4:
            total+=4*counter;
            break;
        case 5:
            total+=5*counter;
            break;
        default:
            printf("please input another number:");
            break;
        }

    }
    printf("%d",total);
}
