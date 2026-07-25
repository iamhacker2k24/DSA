#include <iostream>
using namespace std;

class customer
{
    string name;
    int balance, account_number;

public:
    customer(string name, int balance, int account_number)
    {
        this->name = name;
        this->balance = balance;
        this->account_number = account_number;
    }
    // deposite
    void deposite(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "balance added " << amount << endl;
        }
    }
    // withdrw
    void withdraw(int amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "balace withdraw " << amount << endl;
        }
        else
        {
            // cout << "low balance" << endl;
            throw " \t low balance ";
        }
    }
};
int main()
{
    customer c1("rohit", 5000, 10);
    try
    {
        c1.deposite(500);
        c1.withdraw(6000);
    }
    catch (const char *e)
    {
        cout << "  exception happen" << e;
    }
}