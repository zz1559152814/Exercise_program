#include<stdio.h>
#include<math.h>
void main(void)
{
    int counter;
    float pi,den;
    pi=4;
    printf("time   result\n");
    for(counter=1;counter<10000;counter++)
    {   printf("%-7d",counter);
    den=(2*counter+1)*pow(-1,counter);
        pi=pi+4/den;
        printf("%f\n",pi);
    }
}
