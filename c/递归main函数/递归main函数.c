#include<stdio.h>

void main(m)
{
     static int n;
     printf("%d",n);
     n++;
     main(n);
}
