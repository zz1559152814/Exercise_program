#include<stdio.h>

void main(void)
{
    int x,y,z;
    printf("\nintput two numbers:");
    scanf("%d%d",&x,&y);
    z=x/y;
    if(x%y==0)
    {
        printf("\n%d is %d's times",x,y);
        printf("\n%d",z);
    }
    else
    {
        printf("\nlskzcn");
    }
    getch();
}
