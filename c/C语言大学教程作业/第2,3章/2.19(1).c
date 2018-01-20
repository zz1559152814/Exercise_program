#include<stdio.h>

void main(void)
{
    int a,b,c;

    int sum,average,product,smallest,largest;
    printf("\ninput three different integers:");
    scanf("%d%d%d",&a,&b,&c);
    sum=a+b+c;
    average=sum/3;
    product=a*b*c;
    printf("\n%d\n%d\n",sum,average);
    if(a<c&&b<c)
        printf("%d\n",c);
    else if(a<b&&c<b)
        printf("%d\n",b);
    else if(b<a&&c<a)
        printf("%d\n",a);
    getch();
}
