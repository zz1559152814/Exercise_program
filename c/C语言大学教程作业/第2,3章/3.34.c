#include<stdio.h>

void main(void)
{
    int row,cloumn=1,x;
    scanf("%d",&x);
    while(cloumn<=x)
    {
        if(cloumn==1||cloumn==x)
        {
            row=1;
            while(row<=x)
            {
                printf("* ");
                row++;
            }
            printf("\n");

        }
        else
        {
            row=2;
            printf("* ");
            while(row!=x)
            {
                printf("  ");
                ++row;
            }
            printf("*\n");
        }
        cloumn++;

    }
    getch();

}
