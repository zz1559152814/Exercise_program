#include<stdio.h>

void main(void)
{
    int counter1,counter2,grade;
    counter1=0;
    counter2=0;
    while(counter1<10)
    {
        printf("input the result:");
        scanf("%d",&grade);
        counter1=counter1+1;
        if(grade==1)
            counter2=counter2+1;
    }
    printf("%d",counter2);
    if(counter2>=8)
        printf("prise the teacherr");
        getch();

}
