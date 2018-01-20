#include<stdio.h>

void main(void)
{
    int z;
    printf(":");
    scanf("%d",&z);
    if(z%2==0)
    {
        printf("\neven %d",z);

    }
    else
    {
        printf("\nodd %d",z);
    }
}
