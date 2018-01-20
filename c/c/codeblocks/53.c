#include<stdio.h>

void main(void)
{
    int counter,total,grade,average\
    counter=0;
    total=0;
    printf("input:");
    scanf("%d",&grade);
    while(grade!=-1)
       {

        total=total+grade;
        counter=counter+1;
        scanf("%d",&grade);
       }
    if(grade==-1)
        average=(float)total/counter;
    printf("zhaoxin%d",average);

}
