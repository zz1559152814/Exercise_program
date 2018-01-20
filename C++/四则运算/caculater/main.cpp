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
    string Input1;
    string Input;
    char chofinput;
    Input+='(';
    cin>>Input1;
    Input+=Input1;
    Input+=')';
    cout<<Input<<endl;
    /*ready to load the data from string to stack*/
    int couts=Input.size();
    int couts2=0;
    /*divide data into number and string*/
    char data;           //the content of input
    int flag;            //the flag to get the "(" ")"
    string number;       //the string to save number
    double dataofnumber; //the value to transfer data from string to stack
    double Leftoperand=0;
    double Rightoperand=0;
    int    CTOC=1;       //counts the value of calculations for load left operant
    int    sign=0;
    int    sign2=0;
    while(couts>=1)
    {
        data=Input.at(couts2);
        /*when meet sign*/
        if((int)data>=40&&(int)data<=47&&(int)data!=44)
        {
            /*adjust is it the first load of number,then get the data into stack*/
            if(number.size()!=0)
            {
                //dataofnumber=atof(number.c_str());
                dataofnumber=stringToNum<double>(number);
                /*when last sign is '*' or '/' ,read the left number and use this time's right number to calculate*/
                if(sign==1)
                {
                    if(signstack.getdata()=='*')
                        Leftoperand*=dataofnumber;
                    else if(signstack.getdata()=='/')
                        Leftoperand/=dataofnumber;
                    numstack.pop();
                    signstack.pop();
                    numstack.push(Leftoperand);
                    sign=0;
                }
                else
                {
                    /*deal with bug on minus*/
                    if(signstack.getdata()=='-')
                    {
                        dataofnumber=-dataofnumber;
                        signstack.pop();
                        signstack.push(43);
                    }
                    numstack.push(dataofnumber);
                }
                number.clear();
            }
            signstack.push(data);
            /*when meet *and/ sign set 1 and save the left number ,when next sign come,deal with it*/
            if(data=='*'||data=='/')
            {
                Leftoperand=numstack.getdata();
                sign=1;
            }
            /*deal with the situation of ()*/
            if(data==')')
            {
                CTOC=1;
                signstack.pop();
                while(signstack.getdata()!='(')
                {
                    sign2=2;
                    signstack.pop();
                    if(CTOC==1)
                    {
                        Leftoperand=numstack.getdata();
                        numstack.pop();
                        CTOC=2;
                    }
                    Rightoperand=numstack.getdata();
                    Leftoperand+=Rightoperand;
                    numstack.pop();
                }
                /*deal with the situation of (x) */
                if(sign2==2)
                    numstack.push(Leftoperand);
                signstack.pop();
                /*to deal with the situation of x-(m+n),which '(' is follow '-'*/
                if(signstack.empty()!=1&&signstack.getdata()=='-')
                {
                    Leftoperand=-numstack.getdata();
                    numstack.pop();
                    numstack.push(Leftoperand);
                    signstack.pop();
                    signstack.push(43);
                }
            }
        }
        else if((int)data>=48&&(int)data<=57)
        {
            number+=data;
        }
        else
            return 0;
        --couts;
        ++couts2;
    }
    cout<<"******************************"<<endl;
    numstack.pfstack();
    cout<<"******************************"<<endl;
    signstack.pfstack();
    cout<<"******************************"<<endl;
    cout<<"reault:"<<Leftoperand<<endl;
    return Leftoperand;
}


int tempmain(void)
{
    /*set two stacks for number and sign*/
    mystack<double> numstack;
    mystack<char> signstack;

    /*read the data into a string*/
    string Input1;
    string Input;
    char chofinput;
    Input+='(';
    cin>>Input1;
    Input+=Input1;
    Input+=')';
    cout<<Input<<endl;

    int couts=Input.size();
    int couts2=0;
    /*divide data into number and string*/
    char data;           //the content of input
    int flag;            //the flag to get the "(" ")"
    string number;       //the string to save number
    double dataofnumber; //the value to transfer data from string to stack
    double Leftoperand=0;
    double Rightoperand=0;
    char   Operator;
    int    CTOC=1;       //counts the value of calculations for load left operant
    while(couts>=1)
    {
        data=Input.at(couts2);
        if((int)data>=40&&(int)data<=47&&(int)data!=44)
        {
            /*adjust is it the first load of number,then get the data into stack*/
            if(number.size()!=0)
            {
                //dataofnumber=atof(number.c_str());
                dataofnumber=stringToNum<double>(number);
                numstack.push(dataofnumber);
                number.clear();
            }
            signstack.push(data);
            if((int)data==')')
            {
                CTOC=1;
                signstack.pop();
                while(signstack.getdata()!='(')
                {
                    /*get the data of number*/
                    if(CTOC==1)
                    {
                        Leftoperand=numstack.getdata();
                        cout<<"Leftoperand:"<<Leftoperand<<endl;
                        numstack.pop();
                        ++CTOC;
                    }
                    Rightoperand=numstack.getdata();
                    numstack.pop();
                    /*deal with the data of sign*/
                    Operator=signstack.getdata();
                    switch((int)Operator)
                    {
                    case 43:
                        Leftoperand=Leftoperand+Rightoperand;
                        break;
                    case 45:
                        Leftoperand=Rightoperand-Rightoperand;
                        break;
                    case 42:
                        Leftoperand=Leftoperand*Rightoperand;
                        break;
                    case 47:
                        Leftoperand=Rightoperand/Leftoperand;
                        break;
                    default:
                        cout<<"Operator:"<<Operator<<endl;
                    }
                    signstack.pop();
                }
                signstack.pop();
                numstack.push(Leftoperand);
            }
        }
        else if((int)data>=48&&(int)data<=57)
        {
            number+=data;
        }
        else
            return 0;
        --couts;
        ++couts2;
    }
    cout<<Leftoperand<<endl;
    return Leftoperand;
}

