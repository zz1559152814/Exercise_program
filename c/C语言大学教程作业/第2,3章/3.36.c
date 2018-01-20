#include<stdio.h>
#include<math.h>
void main(void)
{
    int number,counter,q,w,e,r,a;
    scanf("%d",a);
    counter=1;
    q=1;
    e=1;
    r=1;
    number=0;
    while(a/q>10)
    {
        q=q*10;
        counter++;
    }
    while(counter>0)
    {
        w=((a-a%e)/e)%10;
        number=number+w*(2^(r-1));
        e=e*10;
        r++;
        counter--;
    }
    printf("%d\n",w);
    printf("%d\n",2^(r-1));
    printf("%d",number);
}
