#include <iostream>
using namespace std;

class customer
{
    string name;
    int account_number, balance;
    static int total_customar;
    static int total_balance;

public:
    // static int total_customar;
    customer(string name, int account_number, int balance)
    {
        this->name = name;
        this->account_number = account_number;
        this->balance = balance;
        total_customar++;
        total_balance = total_balance + balance;
    }
    static void acceStatic()
    {
        cout << " total_customar  "<< total_customar << endl;
        cout << " total_balance   "<< total_balance << endl;
    }
    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            total_balance += amount;
        }
    }
    void withdraw(int amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            total_balance -= amount;
        }
    }
    void display()
    {
        cout << name << " " << account_number << " " << balance << " " << total_customar << endl;
    }
};
int customer::total_customar = 0;
int customer::total_balance = 0;
int main()
{
    customer A1("rohit", 1, 1000);
    customer A2("rohit", 2, 500);
    // A1.display();
    customer A3("rohit", 2, 900);
    A3.deposit(300);
    // A1.display();
    // A1.display();

    // customer::total_customar = 5;
    // A1.display();
    A3.withdraw(1000);
    // A3.display();
    customer::acceStatic();
    return 0;
}