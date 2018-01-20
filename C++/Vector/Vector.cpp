#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

void outputVector(const vector< int > &);
void intputVector(vector< int >&);

int main(void)
{
    vector< int > integers1(7);
    vector< int > integers2(13);

    cout<<"size of vector integers1 is:"<<integers1.size()<<endl;
    outputVector(integers1);

    cout<<"\nsize of vector integers2 is :"<<integers2.size()<<endl;
    outputVector(integers2);

    cout<<"\nEnter 17 intergers"<<endl;
    intputVector(integers1);
    intputVector(integers2);

    cout<<"\nAfter input ,the vectors contain\n"<<"integers1:"<<endl;
    outputVector(integers1);
    cout<<"\nAfter input ,the vectors contain\n"<<"integers2:"<<endl;
    outputVector(integers2);

}
void outputVector(const vector< int > &array)
{
    size_t i;

    for (i=0;i<array.size();i++)
    {
        cout<<setw(12)<<array[i];

        if((i+1)%4==0)
            cout<<endl;
    }
    cout<<endl;
}

void intputVector(vector< int >&array)
{
    for (size_t i=0;i<array.size();i++)
        cin>>array[i];
}
