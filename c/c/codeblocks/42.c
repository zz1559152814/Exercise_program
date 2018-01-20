#include<stdio.h>
#include<conio.h>
void main(void)
{
    int x=0;
    printf("\n输入一个可以用来描述郭佳薇的数字：");
    scanf("%d",&x);
    if (x==2||x==250||x==290||x==38)
    {
        printf("\n\n\n\nyou are a clear boy!!!!\n\n\n\n");
    }
    else
    {
        printf("\n\n\n\nit seems that you don't understand what she is\n\n\n\n");
    }
    getch();
}
