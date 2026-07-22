#include <iostream>
using namespace std;
class Coustomer
{
    string name;
    int account_number;
    int balance;

public:
    Coustomer(string n, int b, int c)
    {
        name = n;
        account_number = b;
        balance = c;
    }

    void display()
    {
        cout << name << " " << account_number << " " << balance;
    }

    // copy constructor
    Coustomer(Coustomer &B)
    {
        name = B.name;
        account_number = B.account_number + 1;
        balance = B.balance;
    }
    Coustomer()
    {
        name = "";
        account_number = 0;
        balance = 0;
    }
};

int main()
{
    Coustomer A3("dev", 25, 100);
    Coustomer A4(A3);
    A4.display();
    Coustomer A5;
    A5 = A3;
    A5.display();
    return 0;
}