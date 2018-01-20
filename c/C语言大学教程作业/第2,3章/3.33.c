#include<stdio.h>

void main(void)
{
    int row,cloumn=1,x;
    scanf("%d",&x);
    while(cloumn<=x)
    {
        row=1;
        while(row<=x)
        {
            printf("* ");
            row++;
        }
        printf("\n");
        cloumn++;

    }

}
