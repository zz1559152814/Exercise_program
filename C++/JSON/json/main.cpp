#include <fstream>
#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
using std::ifstream;

int main(void)
{
    /*creat error message file*/
    ofstream error_message;
    error_message.open("error message.txt");

    /*read the data from txt to list*/
    ListOperate jsonlist;
    ifstream fdata;
    fdata.open("jsondata.txt",ios::in);;
    ifstream &datatemp=fdata;
    jsonlist.readdatafromfile(datatemp);

    /*set the right list*/
    ListOperate rightlist;
    ifstream rightdata;
    rightdata.open("rightdata.txt",ios::in);;
    ifstream &rdatatemp=rightdata;
    rightlist.readdatafromfile(rdatatemp);
//    rightlist.pflist();

    /*get out of the sign in the list to newlist*/
    ListOperate newlistforsymbol,newlistforword;
    int nodenumber=jsonlist.sizelist();
    char jlistdata,jrightdata;
    for(int i=1; i<=nodenumber; i++)
    {
        jlistdata=jsonlist.getdata(i);
        if(jlistdata==123||jlistdata==125||jlistdata==44||jlistdata==58||jlistdata==34)
            newlistforsymbol.inserttail(jlistdata);
        else
            newlistforword.inserttail(jlistdata);
    }
    newlistforsymbol.pflist();

    /*judge*/
    int number2=rightlist.sizelist();
    int number3=newlistforsymbol.sizelist();
    if(number2!=number3)
    {
        return 2;
    }
    else
    {
        for(int j=1; j<=number2; j++)
        {
            if(newlistforsymbol.getdata(j)!=rightlist.getdata(j))
            {
                return 3;
            }
        }
    }

    /*decide flag of symbol*/
/*    if(jlistdata==rightlist)
        ++start_flag;
    else if(jlistdata=='}')
        --start_flag;
    if(start_flag!=0)
        ++errors;

    if(jlistdata=='\"')
        ++quot_cout;
    else if(jlistdata==':')
        ++colon_cout;
    else if(jlistdata==',')
        ++comma_cout;
    if(2*comma_cout==quot_cout&&quot_cout==colon_cout)
        ++value_cout;
    if(i==nodenumber)
    {
        if(start_flag!=0)
        {
            error_message<<"lack of start_flag or end_flag"<<endl;
            error_message.close();
            return 0;
        }
        if(quot_cout<2*comma_cout&&quot_cout<2*colon_cout)
        {
            error_message<<"in "<<value_cout<<"th value,lack of quot"<<endl;
            error_message.close();
            return 0;
        }
        if(2*colon_cout<comma_cout&&colon_cout<quot_cout)
        {
            error_message<<"in "<<value_cout<<"th value,lack of colon"<<endl;
            error_message.close();
            return 0;
        }
        if(2*comma_cout<colon_cout&&comma_cout<quot_cout)
        {
            error_message<<"in "<<value_cout<<"th value,lack of colon"<<endl;
            error_message.close();
            return 0;
        }
    }
}*/
error_message<<"no error"<<endl;
error_message.close();
return 0;

}
