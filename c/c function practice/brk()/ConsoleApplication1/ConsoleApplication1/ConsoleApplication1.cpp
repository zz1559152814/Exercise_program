// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include "stdio.h"
#include "malloc.h"
#define MAX 500
main()
{
    int *p,n=0,max=MAX;
    FILE *fp;
    clrscr();
    fp=fopen("F:\c\c function practice\brk()\brk.txt","r");
    p=(int*)malloc(MAX*sizeof(int));
    while(!feof(fp))
    {
        if(n==max)
        {
            max=max+MAX;
            brk(p+max);
        }
        fscanf(fp,"%d",&p[n]);
        printf("%d",p[n]);
        n++;
    }
    fclose(fp);
    free(p);
}


