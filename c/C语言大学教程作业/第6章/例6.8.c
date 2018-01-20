
#include<stdio.h>
#define SIZE 10
int main(void)
{
	int n[SIZE]={1,2,3,4,5,6,7,8,9,10};
	int counter;
	int a=0;
	printf("sequence  number    tub\n");
	for (counter=0;counter<SIZE;counter++)
	{
		printf("%-10d%-10d",counter,n[counter]);
		for(a=0;a<n[counter];a++)
		{
			printf("*");
		}
		printf("\n");
	}
}




