#include<stdio.h>

void main(void)
{
    float gallons,meters,total1,total2,average;
    gallons=0;
    total1=0;
    total2=0;
    while(gallons!=-1)
    {
        printf("\nintput gallons:");
        scanf("%f",&gallons);
        if(gallons==-1)
            break;
        printf("\ninput meters:");
        scanf("%f",&meters);
        total1+=gallons;
        total2+=meters;
    }
    average=total1/total2;
    printf("intput:%f",average);
}
