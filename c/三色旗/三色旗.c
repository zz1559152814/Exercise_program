#include<stdio.h>
void inital(int *line,int number);
void main()
{

    int line[100];
    int count;
    int n;
    int color[3]= {0};
    int color_least;

    /*row inital*/
    inital(line,100);

    for(count=0; count<100; count++)
    {
        if(line[count]>count[count+1])
        {
            exchange(&line[count],&line[count+1]);
            n++;
        }
    }
}
void inital(int *line,int number)
{
    int count;
    printf("the inital row:\n");
    srand(time(NULL));
    for(count=1; count<=number; count++)
    {
        line[count-1]=rand()%3;
        printf("%d",line[count-1]);
    }
    printf("\n");
}
void exchange(int a,int b)
{
    int c;
    c=a;
    a=b;
    b=c;
}
