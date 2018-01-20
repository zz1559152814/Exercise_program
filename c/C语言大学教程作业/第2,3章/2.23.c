#include<stdio.h>

void main(void)
{
    int q,w,e,r,t;
    printf("intput:");
    scanf("%d%d%d%d%d",&q,&w,&e,&r,&t);
    if(q>w&&q>e&&q>r&&q>t)
       {
           printf("\nthe largest number is %d",q);
       }
    else if(w>q&&w>e&&w>r&&w>t)
       {
           printf("\nthe largest number is %d",w);
       }
    else if(e>q&&e>w&&e>r&&e>t)
       {
           printf("\nthe largest number is %d",e);
       }
    else if(r>q&&r>e&&r>w&&r>t)
       {
           printf("\nthe largest number is %d",r);
       }
    else if(t>q&&t>e&&t>r&&t>w)
       {
           printf("\nthe largest number is %d",t);
       }
    if(q<w&&q<e&&q<r&&q<t)
        {
            printf("\nthe smallest number is:%d",q);
        }
    else if(w<q&&w<e&&w<r&&w<t)
        {
            printf("\nthe smallest number is:%d",w);
        }
    else if(e<q&&e<w&&e<r&&e<t)
        {
            printf("\nthe smallest number is:%d",e);
        }
    else if(r<q&&r<e&&r<w&&r<t)
        {
            printf("\nthe smallest number is:%d",r);
        }
    else if(t<q&&t<e&&t<r&&t<w)
        {
            printf("\nthe smallest number is:%d",t);
        }
    getch();
}
