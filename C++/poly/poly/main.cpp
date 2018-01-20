#include <iostream>
#include "class.h"
using namespace std;

int main(void)
{
    A *a=NULL;
    B *b=NULL;
    A a1;
    B b1;
    a=&a1;
    b=&b1;
    a->print();
    b->print();
    a=&b1;
    a->print();
    return 0;
}
