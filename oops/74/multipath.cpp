// multiple inherense
#include <iostream>
using namespace std;
class human
{
public:
    string name;
    void display()
    {
        cout << "My name is " << name << endl;
    }
};
class Engineer : public virtual human
{
public:
    string specilization;
    void work()
    {
        cout << " I have specialiazion" << specilization << endl;
    }
};
class youtuber : public virtual human
{
public:
    int suscriber;
};
class codeteacher : public youtuber, public Engineer
{
public:
   
    int salary;
    codeteacher(string name, string specilization, int suscriber, int salary)
    {
        this->name = name;
        this->specilization = specilization;
        this->suscriber = suscriber;
        this->salary = salary;
    }
};
int main()
{
    codeteacher a1("ram", "cse", 490000, 49000);
   a1.display();
    return 0;
}