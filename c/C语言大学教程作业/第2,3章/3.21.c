#include<stdio.h>

void main(void)
{
    int a,b,c;
    while(a!=-1)
    {

        printf("Enter the works hours:");
        scanf("%d",&a);
        if(a==-1)
            break;
        printf("enter the hourly rate of the works:");
        scanf("%d",&b);
        if(a<=40)
        {
            c=(a-40)*10+400;
            printf("salary is:%d",c);
        }
        else
        {
            c=(a-40)*15+400;
            printf("salary is:%d\n",c);
        }
        getchar();
    }

}
