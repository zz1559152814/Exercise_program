#ifdef _LIST_H_
#endif _LIST_H_

#include <iostream>
#define elem double
typedef struct Node
{
    elem data;
    Node *next;
};

class ListOperate
{
public:
    ListOperate(void);

    Node *gethead(void);

    void setphead(Node *p);

    double getdata(int pos);

    void initlist(void);

    void readdatafromfile(void);

    void ListCreat(void);

    void pflist(void);

    int  sizelist();

    void clearlist();

    void returnelem(int pos);

    void findelem(elem indata);

    elem returnelem(int pos,double x );

    void change(int pos,double x);

    void exchange(int pos1 ,int pos2);

    void setnode(int pos,double number);

    void inserthead(elem indata);

    void deletepos(int pos);

    void inserttail(int indata);

    void deletelem(elem ele);

    /*√∞≈›°¢—°‘Ò°¢≤Â»Î°¢øÏ≈≈°¢πÈ≤¢°¢œ£∂˚°¢∂—≈≈–Ú*/
    void bubblesort1();

    void bubblesort2();


//    Node *sortlist();
//    bool insertandsort(elem data);
private:
    Node *phead;
    Node *ptail;
};
