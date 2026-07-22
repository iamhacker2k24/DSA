#include <iostream>
using namespace std;
class Customer
{
    string name;
    int *data;

public:
    Customer()
    {
        name = "rohit";
        data = new int;
        *data = 10;
        cout << "Conctructor is called it has not return type not taking argument..ok \n";
    }
    ~Customer()
    {
        delete data;
        cout << "desstructor  is called it has not return type not taking argument..ok";
    }
};
int main()
{
    Customer A1;

    return 0;
}