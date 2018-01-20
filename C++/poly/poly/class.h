#include <iostream>
using namespace std;
class A
{
    public:
        virtual void print(void);
    private:
        int error;
};

void A::print(void)
{
    cout<<"A"<<endl;
};

class B:public A
{
    public:
        void print(void);
    private:
        int error2;
};

void B::print(void)
{
    cout<<"B"<<endl;
};
