#include<st dio.h>
#include<stdlib.h>

int main()
{
    char *s;
    if((s=malloc(2))==NULL)
    {
        printf("wrong");
        exit(1);
    }
    strcpy(s,"yo");
    printf("%s",s);
    free(s);
    return(0);
}
