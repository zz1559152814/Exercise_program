#include "all.h"

using namespace std;
inline void apptr(Node *p);


int main(void)
{
	ListOperate caculater;
	Node *cphead,*p1;
	int nodecout=0,nodenumber=0;
	int cdata;
    apptr(p1);
    cphead=p1;
    cin>>p1->data;
    while(1)
    {
        ++nodecout;
        p1->pos.pos=nodecout;
        if(p1->data=='(')
        {
            ++nodenumber;
            p1->pos.signofblack=1;
        }
        else
        {
            ++nodenumber;
            p1->pos.signofblack=0;
        }
        cin>>cdata;
        if(cdata=='!')
            break;
        else
            p1->data=cdata;
        cout<<1<<endl;
        apptr(p1->next);
        cout<<2<<endl;
        p1=p1->next;
        cout<<3<<endl;
    }
        cout<<4<<endl;
    caculater.setphead(cphead);
    caculater.pflist();
    return 1;
}

inline void apptr(Node *p)
{
    p=(Node *)malloc(sizeof(Node));
    if(p==NULL)
        cout<<"memory applicate failed"<<endl;
    memset(p,0,sizeof(Node));
}
