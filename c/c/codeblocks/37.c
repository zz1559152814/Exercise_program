#include<stdio.h>

void main(void)
{
  int x,y;
  scanf("%d%*d%d",&x,&y);
  printf("%d %*d %d",x,y);

}
