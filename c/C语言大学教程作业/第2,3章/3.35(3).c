#include<stdio.h>
#include<math.h>
void two_ten(int num[],int sub)
{
    int i;
    double sum=0;
    for(i=0; i<sub; i++)
    {
        sum=sum+num[i]*pow(2,i);
    }
    printf("转换为十进制后为：%.0lf\n",sum);
}

void main()
{
    int arr[200];
    int sub=0;
    do
    {
        printf("请输入二进制数的第%d位,输入2结束:\n",sub+1);
        scanf("%d",&arr[sub]);
        if(arr[sub]!=0&&arr[sub]!=1&&arr[sub]!=2)
        {
            printf("输入错误，请输入0或1，2结束\n");
            sub--;
        }
        if(arr[sub]==2)
        {
            break;
        }
        sub++;

    }
    while(1);
    two_ten(arr,sub);
}
