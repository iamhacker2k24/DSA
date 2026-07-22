#include <iostream>
using namespace std;
class destructor
{

    //~destructor , it auttomatically no need to write, no return type no parameter it take it use for mainly heap memory

    string name;
    int *data;

public:
    destructor()
    {
        data = new int;
        *data = 10;
        cout << "constructor is called \n ";
    }
    ~destructor() // it alawys  call at last
    {
        delete data; // delete dynamacally created data
        cout << "destructor is called";
    }
};
int main()
{
    destructor A;

    return 0;
}