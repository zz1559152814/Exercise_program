#include "stack.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class Type>
Type stringToNum(const string& str)
{
    istringstream iss(str);
    Type num;
    iss >> num;
    return num;
}

int main(void)
{
    /*set two stacks for number and sign*/
    mystack<double> numstack;
    mystack<char> signstack;
    /*read the data into a string*/
    string Input;
    char chofinput;
    cin>>Input;
    int couts=Input.size();
    int couts2=0;
    //cout<<couts;
    /*divide data into number and string*/
    double num_dou;
    double num_str;
    char data;
    int flag;
    string number;
    double dataofnumber;
    while(couts>=1)
    {
        data=Input.at(couts2);
        if((int)data>=40&&(int)data<=47&&(int)data!=44)
        {
            if(number.size()!=0)
            {
                //dataofnumber=atof(number.c_str());
                dataofnumber=stringToNum<double>(number);
                numstack.push(dataofnumber);
                number.clear();
            }
            signstack.push(data);
            if((int)data==40)
            {
                flag++;
            }
            else if((int)data==41)
            {
                flag--;
            }
        }
        else if((int)data>=48&&(int)data<=57)
        {
            number+=data;
        }
        --couts;
        ++couts2;
    }
    numstack.pfstack();
    signstack.pfstack();
    return 1;
    //number=stringToNum<double>(Input);
    /*when meet the left blanket flag++ ,and when meet right blanket get out of the data until the last left blanket into a new stack*/

    /*result the smallest unit and pop the unit replace of push the result in*/

    /*when ptr-tail is null,the whole stack becomes to a final unit*/
}


int tempmain(void)
{
    mystack<int> test;
    test.push(2);
    test.push(1);
    test.push(5);
    test.pfstack();

}
