#include<stdio.h>
#include<math.h>

void main(void)
{
    int number,counter,dividend,dividend2,add;
    printf("���������������");
    scanf("%d",&number);
    counter=1;
    dividend=1;
    add=0;
    while(number/dividend>1)
    {
        dividend*=10;
        counter++;
    }
    printf("������λ����%d\n",counter);
    dividend2=number;
    int i=0;
    while(i<counter)
    {
        /***************************************
        number=((number-number%dividend2)/dividend2)%10;  //���ﲻ�ԣ���������number=10��number-number%dividend2������10-10=0�˰���
        add=add+number*x;
        dividend2=dividend2*10;
        *****************************************/
        add=add+(dividend2%10)*pow(2.0,i);
        dividend2=dividend2/10;
        i++;
    }
    printf("����Ķ��������ǣ�%d\n",number);
    printf("�����ʮ�������ǣ�%d\n",add);

}
