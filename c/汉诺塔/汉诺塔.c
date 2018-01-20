#include<stdio.h>

void tower(int n,int start,int end,int pass);

void main(void)
{
    int n;
    printf("input the nunber you want:");
    scanf("%d",&n);
    tower(n,1,2,3);
}
void tower(int n,int start,int end,int pass)
{
    if(n==2)
    {
        printf("%d->%d\n",start,pass);
        printf("%d->%d\n",start,end);
        printf("%d->%d\n",pass,end);
    }
    else{
        tower(n-1,start,pass,end);
        printf("%d->%d\n",start,end);
        tower(n-1,pass,end,start);
    }
}
