2#include<stdio.h>
#include<math.h>
int main()
{
    int num;
    int bit;
    int i=4;
    int j;
    printf("please printf the number between 0 and 32767:");
    scanf("%d",&num);
    while(num/pow(10,i)<1)
        i--;
    for(j=1;j<=i+1;j++)
    {
        int a[i+1];
        if(j==1)
            a[j-1]=num%(int)pow(10,j);
        else
            a[j-1]=((num-a[j-2])%(int)pow(10,j))/pow(10,j-1);
        printf("%d  ",a[j-1]);
    }

}
