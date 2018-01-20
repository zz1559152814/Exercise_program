#include <stdio.h>
#define N 12
void printf_number(int i);
void main(void)
{
    int i;/*row and line*/
    int n=N;
    for(i=1;i<=n;i++)
    {
        int j;
        j=i;
        for(N-j;j<=N;j++)
            printf("  ");
        printf_number(i);
        printf("\n");
    }
}
void printf_number(int i)
{
     int j=1;
     for(j;j<=i;j++)
        printf("%3d   ",1+(j-1)*(i-j));
}
