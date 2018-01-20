#include<stdio.h>
float average(float a, float b, float c)
{
    return (a + b + c) / 3;
}
void main(void)
{
    float a = 1, b = 3, c = 3;
    float a2 = 3233, b2 = 4354, c2 = 2345;
    float a3 = 235, b3 = 323345, c3 = 345;

    float y = average(a, b, c);
    float y2 = average(a2, b2, c2);
    float y3 = average(a3, b3, c3);
    printf("\nthe average is %f", y);
    printf("\nthe average is %f", y2);
    printf("\nthe average is %f", y3);
}




