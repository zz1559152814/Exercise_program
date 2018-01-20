#include<stdio.h>
#include<math.h>

void main(void)
{
    int number,counter,dividend,dividend2,add;
    printf("请输入二进制数：");
    scanf("%d",&number);
    counter=1;
    dividend=1;
    add=0;
    while(number/dividend>1)
    {
        dividend*=10;
        counter++;
    }
    printf("二进制位数：%d\n",counter);
    dividend2=number;
    int i=0;
    while(i<counter)
    {
        /***************************************
        number=((number-number%dividend2)/dividend2)%10;  //这里不对，比如输入number=10，number-number%dividend2，就是10-10=0了啊。
        add=add+number*x;
        dividend2=dividend2*10;
        *****************************************/
        add=add+(dividend2%10)*pow(2.0,i);
        dividend2=dividend2/10;
        i++;
    }
    printf("输入的二进制数是：%d\n",number);
    printf("计算出十进制数是：%d\n",add);

}
