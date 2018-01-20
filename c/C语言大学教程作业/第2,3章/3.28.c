#include<stdio.h>

void main(void)
{
    int result;
    int counter=1,counter1=0,counter2=0;
    int pass;
    int fail;
    while(result!=-1)
    {
        printf("input the result:");
        scanf("%d",&result);
        if(result!=1&&result!=2&&result!=-1)\*这里有点小问题，为什么这里要有result！=-1*\
        {
            printf("please int the right result:");
            scanf("%d",&result);
        }
        if(result==1)
            ++counter1;
        else if(result==2)
            ++counter2;
        ++counter;
    }
    if(counter>8)
        printf("bonus to instuctor\n");
    printf("%d,%d,%d",counter,counter1,counter2);
}
