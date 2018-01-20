#include<stdio.h>
int even(int number);
void main()
{
    int number;
    printf("please input the number you want:");
    scanf("%d",&number);
    if(even(number)==1)
        printf("even");
    else
        printf("odd");
    getch();
}
int even(number)
{
    return(number%2+1);
}
