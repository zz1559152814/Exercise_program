#include <stdio.h>
#include <stdlib.h>
#include "string"
#include "stdafx.h"

typedef int eleType;

typedef struct node
{
    eleType element;
    Node * next;
}Node;

void initlist(Node **node)
{
    *node=NULL;
    printf("initlist start");
}

Node *creatlist(Node *pHead)
{
    Node p1;
    Node p2;

    p1=p2=(Node *)malloc(sizeof(Node));
    if(p1==NULL||p2==NULL)
    {
        printf("list creat failed");
        exit(0);
    }
    memset(p1,0,sizeof(Node));

    scanf("%d",&p1->element);
    while(p1->element>0)
    {
        if(pHead==NULL)
        {
            pHead=p1;
            pHead->next=p2;
        }
        else
        {
            p2->next=p1;
        }
        p2=p1;
        p1=(Node *)malloc(sizeof(Node));
        if(p1==NULL||p2==NULL)
        {
            printf("list creat failed");
            exit(0);
        }
        memset(p1,0,sizeof(Node));
        p1->NULL;
    }
    printf("success");
    return  pHead;
}
