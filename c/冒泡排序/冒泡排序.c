#include <stdio.h>

void main(void)
{
    int data[10];
    int temp;
    int m;
    int j;
    for(j=0;j<10;j++)
        scanf("%d",data[j]);
    for(j=1;j<10;j++)
    {
        m=j;
        while(data[m]<data[m-1])
        {
            temp=data[m];
            data[m]=data[m-1];
            data[m-1]=temp;
            m--;
        }
    }
    for(j=0;j<10;j++)
        printf("%d  ",data[j]);
}
