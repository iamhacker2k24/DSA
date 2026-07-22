// danamacally handelling clss

#include <iostream>
using namespace std;

class student
{
public:
    string name;
    int roll;
};
int main()
{

    student *s = new student;
    (*s).name = "dev";
    cout<<(*s).name<<endl;

    return 0;
}
