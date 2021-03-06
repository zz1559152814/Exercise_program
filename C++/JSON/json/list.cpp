#include<fstream>
#include <iostream>
#include "list.h"
#include <string.h>
#include <malloc.h>
#include <iostream>
using namespace std;

ListOperate::ListOperate(void)
{
    phead=NULL;
}

void ListOperate::setphead(Node *p)
{
    phead=p;
}

Node *ListOperate::gethead(void)
{
    return phead;
}

double ListOperate::getdata(int pos)
{
    Node *p1;
    p1=phead;
    for(int i=1; i<pos; i++)
    {
        p1=p1->next;
    }
    return p1->data;
}

void ListOperate::ListCreat(void)
{
    Node *p;
    char temp;
    cin>>temp;
    if(temp!=33)
    {
        p=(Node *)malloc(sizeof(Node));
        if(p==NULL)
        {
            cout<<"p memory applicate failed"<<endl;
        }
        memset(p,0,sizeof(Node));
        phead=p;
        p->data=temp;
    }
    else
        return;
    while(p->data!=33)
    {
        cin>>temp;
        if(temp==33)
            return;
        else
        {
            p->next=(Node *)malloc(sizeof(Node));
            if(p->next==NULL)
            {
                cout<<"p->next memory applicate failed"<<endl;
            }
            memset(p->next,0,sizeof(Node));
            p->next->data=temp;
            p=p->next;
        }
        p->next=NULL;
    }
    return(l);
}

void ListOperate::initlist()
{
    phead=(Node *)malloc(sizeof(Node));
    if(phead==NULL)
    {
        cout<<"failed"<<endl;
    }
    memset(phead,0,sizeof(Node));
    phead->next==NULL;
}

void ListOperate::readdatafromfile(ifstream &fdata)
{
    char ch;
    Node *p1;
    p1=(Node *)malloc(sizeof(Node));
    if(p1==NULL)
    {
        cout<<"memory applicate failed"<<endl;
    }
    memset(p1,0,sizeof(Node));
    phead=p1;
    while(fdata.peek()!=EOF)
    {
        fdata>>ch;
        cout<<ch;
        p1->data=ch;
        if(fdata.peek()!=EOF)
        {
            p1->next=(Node *)malloc(sizeof(Node));
            if(p1->next==NULL)
            {
                cout<<"memory applicate failed"<<endl;
            }
            memset(p1->next,0,sizeof(Node));
            p1=p1->next;
        }
    }
}

void ListOperate::pflist(void)
{
    Node *p1;
    p1=phead;
    while(p1!=NULL)
    {
        cout<<"the member of list:"<<p1->data<<endl;
        p1=p1->next;
    }
}

int ListOperate::sizelist()
{
    int sizeoflist=0;
    Node *p;
    p=phead;
    while(p!=NULL)
    {
        p=p->next;
        ++sizeoflist;
    }
    cout<<"there is "<<sizeoflist<<" members in the list"<<endl;
    return sizeoflist;
}

void ListOperate::clearlist()
{
    Node *p1;
    while(phead!=NULL)
    {
        p1=phead;
        while(p1->next!=NULL)
        {
            p1=p1->next;
        }
        free(p1);
    }
    exit(0);
}

void ListOperate::returnelem(int pos)
{
    int n=1;
    Node *p1;
    p1=phead;
    while(pos>n||p1==NULL)
    {
        if(p1->next==NULL)
        {
            cout<<"pos is overstep the boundary"<<endl;
            return;
        }
        p1=p1->next;
        ++n;
    }
    cout<<"the "<<pos<<"'th menber of list is "<<p1->data<<endl;
}

void ListOperate::findelem(elem indata)
{
    Node *p;
    p = phead;
    while(p!=NULL&&p->data!=indata)
    {
        p=p->next;
    }
    if(p==NULL)
        cout<<indata<<" is not in the list"<<"\n"<<endl;
    else
        cout<<indata<<" is in the list"<<"\n"<<endl;
}

void ListOperate::change(int pos,double x)
{
    Node *p1;
    int n=1;
    p1=phead;
    while(n!=pos)
    {
        ++n;
        p1=p1->next;
        if(p1==NULL)
        {
            return;
            cout<<pos<<" is over the boundary"<<endl;
        }
    }
    p1->data=x;
    return;
}

void ListOperate::setnode(int pos,double number)
{
    Node *p1;
    p1=phead;
    for(int i=1; i<pos; i++)
    {
        p1=p1->next;
    }
    p1->data=number;
}

void ListOperate::exchange(int pos1 ,int pos2)
{
    Node *p1;
    p1=phead;
    double data1=getdata(pos1);
    double data2=getdata(pos2);
    setnode(pos1,data2);
    setnode(pos2,data1);
}

void ListOperate::inserthead(elem indata)
{
    Node *p1;
    p1=(Node *)malloc(sizeof(Node));
    if(p1==NULL)
    {
        cout<<"memory applicate failed"<<endl;
        return;
    }
    memset(p1,0,sizeof(Node));
    p1->data=indata;
    p1->next=phead;
    phead=p1;
    return;
}

void ListOperate::inserttail(int indata)
{
    Node *p1;
    if(phead==NULL)
    {
        ptail = (Node *)malloc(sizeof(Node));
        if(ptail==NULL)
        {
            cout<<"ptail memory applicate failed"<<endl;
        }
        memset(ptail,0,sizeof(Node));
        phead=ptail;
    }
    else
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node));
        if(p==NULL)
        {
            cout<<"p->next memory applicate failed"<<endl;
        }
        memset(p,0,sizeof(Node));
        ptail->next=p;
        ptail=ptail->next;
    }
    ptail->data=indata;
    ptail->next=NULL;
    return;
}

void ListOperate::deletepos(int pos)
{
    Node *p1;
    Node *p2;
    int n=1;
    p1=phead;
    p2=p1->next;
    if(pos==1)
    {
        free(phead);
        phead=p2;
    }
    else
    {
        while((n+1)!=pos)
        {
            p1=p2;
            p2=p1->next;
            if(p2==NULL)
            {
                cout<<"pos is cross the border"<<endl;
            }
            ++n;
        }
        p1->next=p2->next;
        free(p2);
    }
}

void ListOperate::deletelem(elem ele)
{
    Node *p1,*p1_temp;
    p1=phead;
    if(phead->data==ele)
    {
        free(phead);
        phead=phead->next;
    }
    else
    {
        while(p1->next!=NULL)
        {
            while(p1->next->data==ele)
            {
                free(p1->next);
                p1->next=p1->next->next;
                if(p1->next==NULL)
                    return;
            }
            p1=p1->next;
            cout<<2;
        }
    }
}

void ListOperate:: bubblesort1()
{
    Node *p1;
    p1=phead;
    int sizeoflist1=sizelist();
    double data[sizeoflist1];
    for(int i=0; i<sizeoflist1; i++)
    {
        data[i]=p1->data;
        p1=p1->next;
    }
    int temp;
    int m;
    for(int j=1; j<sizeoflist1; j++)
    {
        m=j;
        while(data[m]<data[m-1])
        {
            temp=data[m];
            data[m]=data[m-1];
            data[m-1]=temp;
            m--;
        }
    }

    Node *p2;
    p2=phead;
    for(m=0; m<sizeoflist1; m++)
    {
        p2->data=data[m];
        p2=p2->next;
    }
}

void ListOperate::bubblesort2()
{
    int m;
    int pos=1;
    int sizeoflist2=sizelist();
    for(pos; pos<sizeoflist2; pos++)
    {
        m=pos;
        while(getdata(m)>getdata(m+1))
        {
            exchange(m,m+1);
            m--;
        }
    }
}




