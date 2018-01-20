#include<stdio.h>
#include<math.h>
int prime(int number);

void main(void)
{
    int number;
    int n;
//    printf("please input the number:");
//    scanf("%d",&number);
    for(n=1;n<100;n++)
    {
        if(prime(n))
            printf("%d is a prime.\n",n);
        else
            printf("%d is not a prime.\n",n);
    }
}
int prime(int number)
{
    int n;
    for(n=2;n<=(int)sqrt(number);n++)
    {
        if(number%n==0)
            return 0;

    }
    return 1;
}
