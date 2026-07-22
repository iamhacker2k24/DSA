#include <iostream>
using namespace std;
class constructor_1
{
public:
    int roll;
    string name;
    int balance;

public:
    constructor_1() // in this way we create constructor  // this is default constructor 
    {
        cout << "constructor working" << endl;
    }
};

int main()
{
    constructor_1 a1;
    a1.name = "dev";
    cout << a1.name << "";

    return 0;
}