#include<stdio.h>

void main(void)
{
    int a,b,l,s,q;
    a=1;
    printf("intput the number;");
    scanf("%d",&l);
    printf("intput the number;");
    scanf("%d",&s);
    if(s>l)
    {
        q=l;
        l=s;
        s=q;
    }
    while(a<=8)
    {
        printf("intput the number;");
        scanf("%d",&b);
        if(b>l)
        {

            s=l;
            l=b;
        }
        else if(b<l&&b>s)
            s=b;
        a+=1;

    }
    printf("%d,%d",l,s);

}
