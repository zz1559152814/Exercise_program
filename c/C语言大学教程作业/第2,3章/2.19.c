#include<stdio.h>
#include<math.h>

void main(void)
{
    int a,b,c;
    int max(int a,int b);
    int min(int a,int b);
    int sum,average,product,smallest,largest;
    printf("\ninput three different integers:");
    scanf("%d%d%d",&a,&b,&c);
    sum=a+b+c;
    average=sum/3;
    product=a*b*c;
    smallest=min(a,b);
    largest=max(a,b);
    printf("\n%d%d%d%d%d",sum,average,smallest,largest);


}
