#include <iostream>
using namespace std;
class constructor_1
{
public:
    int roll;
    string name;
    int balance;
    int *roi;

public:
    constructor_1() // in this way we create constructor  // this is default constructor // if we crearte manually constructor then compiler not cretae that manually
    {
        // all constructor name are same but taking differnet argumat ,
        cout << "constructor working" << endl;
        name = "rohit";
        roll = 5;
        balance = 100;
        roi = new int[100];
    }
    constructor_1(string a, int b, int c)
    {
        roll = b;
        balance = c;
        name = a;
    }
    void display()
    {
        cout << name << "  " << balance << " " << roll << endl;
    }

    //copy constructor 
    constructor_1(constructor_1 &B){
        name=B.name;
    }

};

int main()
{
    constructor_1 a1;
    constructor_1 a2("devika", 5, 51);
    // a1.name = "dev";D
    // cout << a1.name << "";
    // a1.display();
    a2.display();
    constructor_1 a4(a2); /// by default copy constructor presence in the class
    a4.display();

    return 0;
}