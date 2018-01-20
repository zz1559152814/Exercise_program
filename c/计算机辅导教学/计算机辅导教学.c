#include<stdio.h>
#include<math.h>
#include<time.h>

int creatproblem(int level);

void main(void)
{
    srand(time(NULL));
    int x,y;
    int n;
    int level;
    int count=0;
    int result;
    int creat,jud;
    printf("please select the level:");
    scanf("%d",&level);
    while(1)
    {
        for(n=0; n<10; n++)
        {
            creat=creatproblem(level);
            scanf("%d",&result);
            printf("\n");
            jud=judge(creat,result);
            if(jud)
                count++;
        }
        if(count>=8)
        {
            printf("\nCongratulation,you are ready to go to the next level\n");
            level++;
        }
        else
            printf("\nPlease do it again.\n");
    }
}
int creatproblem(int level)
{
    int x=0;
    int y=0;
    int n;
    for(n=0; n<level; n++)
    {
        x+=((rand()%10)*pow(10,n));
        y+=((rand()%10)*pow(10,n));
    }
    printf("%d*%d=",x,y);
    return x*y;
}
int judge(int n,int result)
{
    if(n==result)
        return 1;
    else
        return 0;
}
