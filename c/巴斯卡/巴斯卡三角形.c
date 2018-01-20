#include<stdio.h>
#define N 12
int get_number(int m,int n);

void main(void)
{
    int space;
    int i;
    int j;
    int k;
    for(i=1;i<=N;i++)
    {
        for(j=N-i;j>0;j--)
        {
            printf("  ");
        }
        for(k=i;k>0;k--)
        {
            printf("%3d ",get_number(i,i-k+1));
        }
        printf("\n");
    }
}
int get_number(int m,int n)
{
    if(m==n||n==1)
        return 1;
    else
        return get_number(m-1,n-1)+get_number(m-1,n);
}
/*#include <stdio.h>
#define N 12
long combi(int n, int r)
{
    int i;
    long p = 1;
    for(i = 1; i <= r; i++)
        p = p * (n-i+1) / i;
    return p;
}
void paint()
{
    int n, r, t;
    for(n = 0; n <= N; n++)
    {
        for(r = 0; r <= n; r++)
        {
            int i;
            if(r == 0)
            {
                for(i = 0; i <= (N-n); i++)
                    printf(" ");
            }
            else
            {
                printf(" ");
            }
            printf("%3d", combi(n, r));
        }
        printf("\n");
    }
}
*/
