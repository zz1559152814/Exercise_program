//#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <fstream>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct jsonlist
{
    char jsondata;
    jsonlist *next;
};
int main(void)
{
    /*creat error message file*/
    ofstream error_message;
    error_message.open("error message.txt");
    int nodenumber=0;
    /*read the data from txt to list*/
    ifstream json;
    json.open("test.txt",ios::in);
    char ch;
    jsonlist *p1;
    jsonlist *jphead;
    p1=(jsonlist *)malloc(sizeof(jsonlist));
    if(p1==NULL)
    {
        cout<<"memory applicate failed"<<endl;
    }
    memset(p1,0,sizeof(jsonlist));
    jphead=p1;
    while(!json.eof())
    {
        ++nodenumber;
        json.get(ch);
        p1->jsondata=ch;
        p1->next=(jsonlist *)malloc(sizeof(jsonlist));
        if(p1->next==NULL)
        {
            cout<<"memory applicate failed"<<endl;
        }
        memset(p1->next,0,sizeof(jsonlist));
        p1=p1->next;
    }
    json.close();
    /*do the judge of the list*/
    int value_cout=0;
    int start_flag=0;
    int quot_cout=0,colon_cout=0,comma_cout=0;
    jsonlist *jp;
    jp=jphead;
    for(nodenumber; nodenumber>=0; nodenumber--)
    {
        /*decide flag of "{" "}"*/
        if(jp->jsondata=='{')
            ++start_flag;

        else if(jp->jsondata=='}')
        {
            --start_flag;
            if(start_flag!=0)
            {
                error_message<<"lack of start_flag or end_flag"<<endl;
                error_message.close();
                return 0;
            }
        }

        if(jp->jsondata=='\"')
            ++quot_cout;
        else if(jp->jsondata==':')
            ++colon_cout;
        else if(jp->jsondata==',')
        {
            ++comma_cout;
        }
        if(2*comma_cout==quot_cout&&quot_cout==colon_cout)
            ++value_cout;
        else
        {
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
        jp=jp->next;
    }
    error_message<<"no error"<<endl;
    error_message.close();
    return 1;
}
