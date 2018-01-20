#include<stdio.h>

void main(void)
{
    int n1,n2,n3,n4,n5,counter;
    scanf("%d %d %d %d %d",&n1,&n2,&n3,&n4,&n5);
    for(counter=1; counter<=n1; counter++)
        printf("*");
    printf("\n");
    for(counter=1; counter<=n2; counter++)
        printf("*");
    printf("\n");
    for(counter=1; counter<=n3; counter++)
        printf("*");
    printf("\n");
    for(counter=1; counter<=n4; counter++)
        printf("*");
    printf("\n");
    for(counter=1; counter<=n5; counter++)
        printf("*");
    printf("\n");
}
