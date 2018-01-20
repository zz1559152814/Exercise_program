#include<stdio.h>

float factiral(int y);

void main(void)
{
    int counter;
    float element,e;
    counter=1;
    e=1;
    while(counter<100)
    {
        element=1/factiral(counter);
        e+=element;
        counter++;
    }
    printf("%f",e);

}
float factiral(int y)
{
    int number;
    number=1;
    while(y>0)
    {
        number*=y;
        y--;
    }
    return number;
}
