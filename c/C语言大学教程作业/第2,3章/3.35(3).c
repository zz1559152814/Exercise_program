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
    printf("ת��Ϊʮ���ƺ�Ϊ��%.0lf\n",sum);
}

void main()
{
    int arr[200];
    int sub=0;
    do
    {
        printf("��������������ĵ�%dλ,����2����:\n",sub+1);
        scanf("%d",&arr[sub]);
        if(arr[sub]!=0&&arr[sub]!=1&&arr[sub]!=2)
        {
            printf("�������������0��1��2����\n");
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
