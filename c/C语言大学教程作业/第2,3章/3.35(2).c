#include<stdio.h>
#include<math.h>
void main(void)
{
    int number,counter,dividend,dividend2,add,x,counter2;
    scanf("%d",&number);
    counter=1;
    dividend=1;
    dividend2=1;
    add=0;
    counter2=0;
    while(number/dividend>1)
    {
        dividend*=10;
        counter++;
    }
    printf("%d\n",counter);
    while(counter>0)
    {
        x=pow(2,counter2);
        number=((number-number%dividend2)/dividend2)%10;
        add=add+number*x;
        dividend2=dividend2*10;
        counter2++;
        counter--;
    }
    printf("%d\n",number);
    printf("%d",add);
}
