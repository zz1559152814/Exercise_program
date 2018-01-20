#include<stdio.h>
int main(void)
{
    int score[40]={1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,9,9,9,9};
    int number[11]={0};
    int counter;
    for(counter=0; counter<40; counter++)
    {
        ++number[score[counter]];
    }
    int a=1;
    for(a=1; a<=10; a++)
    {
    printf("%-10d%            -10d\n",a,number[a]);
    printf("%-10d%            -10d\n",a,number[a]);
    }
}
