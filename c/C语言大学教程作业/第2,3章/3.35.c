#include<stdio.h>

void main(void)
{
    int a,q,w,e,r,t;
    scanf("%d",&a);
    if(a/10000<1||a/10000>10)
    {

        printf("wrong");
        scanf("%d",&a);
    }
    else
    {
        q=a%10;
        w=((a-a%10)/10)%10;
        e=((a-a%100)/100)%10;
        r=((a-a%1000)/1000)%10;
        t=((a-a%10000)/10000)%10;
        if(q==t&&w==r)
            printf("succed");
        else
            printf("wrong");

    }
    getch();
}
