#include<stdio.h>
#include<math.h>
float factiral(int y);

void main(void)
{
    int counter,molecule,x;
    float element,e;
    scanf("%d",&x);
    counter=1;
    e=1;
    while(counter<4)
    {
        molecule=pow(x,counter-1);
        element=molecule/factiral(counter);
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
