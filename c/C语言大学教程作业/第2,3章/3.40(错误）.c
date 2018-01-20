#include<stdio.h>

void main(void)
{
    int counter,row;
    row=1;
    counter=1;
    while(row<=8)
    {
        if(row%2==1)
        {counter=1;
            while(counter<=8)
            {
                if(counter%8!=0)
                    printf("* ");
                else
                printf("* \n");
                counter++;
            }

        }
        else
        {counter=1;

            while(counter<=8)
            {
                if(counter%8!=0)
                    printf(" *");
                else
                    printf(" *\n");counter++;
            }

        }
        row++;
    }

}
