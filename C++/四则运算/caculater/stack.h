#include <iostream>
#include <fstream>
#include <malloc.h>
#include <string.h>

using namespace std;
template<typename T>
struct node
{
    T data;
    node<T> *prev;
    node<T> *next;
};

template <typename T>
class mystack
{
public:

    mystack();

    void push(T sdata);

    bool empty(void) const;

    void pop();

    T getdata(void);

    void pfstack(void);

private:

    node<T> *ptail;

};
template <typename T>
mystack<T>::mystack()
    :ptail(NULL)
{
}

template <typename T>
void mystack<T>::push(T sdata)
{
    node<T> *p1=NULL;
    if(ptail==NULL)
    {
        p1=(node<T> *)malloc(sizeof(node<T>));
        if(p1==NULL)
            cout<<"memory applicate failed"<<endl;
        memset(p1,0,sizeof(node<T>));
        p1->data=sdata;
        p1->prev=NULL;
        p1->next=NULL;
        ptail=p1;
    }
    else
    {
        p1=(node<T> *)malloc(sizeof(node<T>));
        if(p1==NULL)
            cout<<"memory applicate failed"<<endl;
        memset(p1,0,sizeof(node<T>));
        p1->data=sdata;
        p1->prev=ptail;
        p1->next=NULL;
        ptail=p1;
    }
}

template <typename T>
void mystack<T>::pop(void)
{
    node<T> *tempptail;
    tempptail=ptail;
    if(ptail!=NULL)
    {
        ptail=ptail->prev;
        free(tempptail);
    }
    else
        cout<<"the stack is empty"<<endl;
}

template <typename T>
void mystack<T>::pfstack(void)
{
    node<T> *p1;
    p1=ptail;
    while(p1!=NULL)
    {
        cout<<p1->data<<endl;
        p1=p1->prev;
    }
}

template <typename T>
T mystack<T>::getdata(void)
{
    return ptail->data;
}

template <typename T>
bool mystack<T>::empty(void) const
{
    if(ptail==NULL)
        return true;
    else
        return false;
}
