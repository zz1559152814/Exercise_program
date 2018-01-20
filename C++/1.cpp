#include <fstream>
#include <string.h>
#include <malloc.h>
#include <iostream>

using namespace std;

int main(void)
{
    ifstream fdata;
    fdata.open("test.txt",ios::in);
    char ch;
    fdata.get(ch);
    
    cout<<"the member of list:"<<ch<<endl;
}
