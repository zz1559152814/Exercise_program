#include <iostream>
#include "list.h"
#include <string.h>
#include <malloc.h>
#include <iostream>
#include "time.h"
using namespace std;
void initlist(Node *p);

int main(void)
{
    ListOperate my_list;
    my_list.ListCreat();
    cout<<my_list;
}

void putextratestcode(void)
{
    ListOperate my_list;
    /*test of listcreat*/
    my_list.ListCreat();
    /*test of gethead*/
    Node *my_phead;
    my_phead=my_list.gethead();

    /*test of sizelist*/
    my_list.pflist();

    /*test of sizelist*/
    my_list.sizelist();

    /*test of returnelem*/
    my_list.returnelem(4);

    /*test of findelem*/
    my_list.findelem(3);

    /*test of change*/
    my_list.change(2,620);
    my_list.pflist();

    /*test of inserthead*/
    my_list.inserthead(1021);
    my_list.pflist();

    /*test of deletepos*/
    my_list.deletepos(2);
    my_list.pflist();

    /*test of inserttail*/
    ListOperate test_list;
    Node *head;
    test_list.inserttail(2);
    test_list.inserttail(3);
    test_list.inserttail(4);
    test_list.pflist();

    /*test of detelelem*/
    my_list.ListCreat();
    my_list.deletelem(2);
    my_list.pflist();

    /*test of bubblesort*/
    my_list.ListCreat();
    my_list.readdatafromfile();
    my_list.bubblesort2();
    my_list.pflist();
}
