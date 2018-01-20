#include<stdio.h>

void main(void)
{
    int x,a,b=1;
    scanf("%d",&x);
    while(b<=x)
    {
        if(b==1||b==x)
        {
            a=1;
            while(a<=x)
            {
                printf("*");
                a++;
            }
            printf("\n");
        }
        else
        {
            a=1;
            while(a<=x)
            {
                if(a==x||a==1)
                    printf("*");
                else
                    printf(" ");

                ++a;
            }
            printf("\n");
        }
        ++b;
    }
}
