#include <iostream>
using namespace std;
class human
{
protected:
    string name;
    int age;

public:
    ~human()
    {
        cout << "hello human \n";
    }
    void work()
    {
        cout << "i am working \n";
    }
};

class student : public human
{
    int roll_number, fees;

public:
    // student(string name, int age, int roll_number, int fees)
    // {
    //     this->name = name;
    //     this->age = age;
    //     this->roll_number = roll_number;
    //     this->fees = fees;
    // }
    ~student()
    {
        cout << "hello student \n";
    }
};

int main()
{

    // student A1("Dev", 26, 23, 54);
    student A2;
    // A1.work();
    return 0;
}