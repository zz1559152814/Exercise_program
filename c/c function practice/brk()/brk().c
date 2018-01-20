#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#define MAX 500
main()
{
    int *p,n=0,max=MAX;
    FILE *fp;
    system("cls");
    fp=fopen("f:\\aa.txt","r");
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
