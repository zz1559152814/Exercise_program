// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
void main(void)
{
    int i,n,m;
    int Pascal[13][13]= {0};
    Pascal[0][0]=1;
    Pascal[1][0]=1;
    Pascal[1][1]=1;
    for(m=3; m<=13; m++)
    {
        for(n=m; n>=0; n--)
        {
            if(n==m||n==1)
                Pascal[m][n]=1;
			else
				Pascal[m][n]=Pascal[m-1][n-1]+Pascal[m-1][n];
        }
    }
    for(i=1; i<=13; i++)
    {
        for(n=14-i; n>0; n--)
        {
            (" ");
            for(m=i;m>=0;m--)
            printf("%d ",Pascal[i][14-m]);
        }
    }
}
