#include<stdio.h>
#include<math.h>
void main()
{
    int system1,system2;
    int number,number2;
    int interge;
    double decimals;
    int *s1,*s2,*s3;
    int i=0,j=0,x,k;
    scanf("%d",&system1);
    scanf("%d",&system2);
    scanf("%f",number);

    interge=(int)number;
    decimals=number-interge;

    for(x=10;interge/x<1;x*=10)
    {
        s1[i]=interge%x;
        i++;
        if(s1[i]>=system1)
        {
            printf("wrong");
            break;
        }
    }
    s3=s1;
    for(j=0;s3[j]<system2;j++)
    {
        s2[j]=s3[j]%system2;
        s3[j+1]=s3[j+1]*system1+(s1[i]-s2[i])/system2;
        j++;
    }
    k=0;
    for(;j<=0;j--)
    {
        number2+=s2[k]*pow(10,k);
        k++;
    }
    printf("%d",number2);
}

