#ifdef _LIST_H_
#endif _LIST_H_

#include <iostream>
#define elem double
typedef struct Node
{
    int data;
    Node *next;
};

class ListOperate
{
    friend int &justatest(ListOperate &listf,int &a);
public:
    operator double();

    ListOperate(void);

    Node *gethead(void) const;

    void setphead(Node *p);

    double getdata(int pos) const;

    void initlist(void);

    void readdatafromfile(void);

    void ListCreat(void);

    void pflist(void) const;

    int  sizelist() const;

    void clearlist() const;

    void returnelem(int pos) const;

    void findelem(elem indata) const;

    elem returnelem(int pos,double x ) const;

    void change(int pos,double x) const;

    void exchange(int pos1 ,int pos2) const;

    void setnode(int pos,double number) const;

    void inserthead(elem indata);

    void deletepos(int pos);

    void inserttail(int indata);

    void deletelem(elem ele);

    /*√∞≈›°¢—°‘Ò°¢≤Â»Î°¢øÏ≈≈°¢πÈ≤¢°¢œ£∂˚°¢∂—≈≈–Ú*/
    void bubblesort1() const;

    void bubblesort2() const;


//    Node *sortlist();
//    bool insertandsort(elem data);
private:

    Node *phead;

    Node *ptail;
};

