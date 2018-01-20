#include <iostream>
#include <string>
using namespace std;

class GradeBook
{
public:
    GradeBook()
    {
        coursename="math";
    }
    void GetString(string name)
    {
        coursename=name;
    }
    void displayMessage()
    {
        cout<<"Welcome to the grade book for "<< coursename <<endl;
    }
private:
    string coursename;
};

int main()
{
    string a;
    GradeBook mygradebook;
/*
    cout<<"please input the course name" <<endl;
    cin>>coursename;
*/

   cout<<"please input the course name" <<endl;
    getline(cin,a);
    cout<<endl;

    mygradebook.GetString(a);
  mygradebook.displayMessage();
}
