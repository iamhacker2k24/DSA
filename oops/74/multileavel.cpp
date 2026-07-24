#include <iostream>
using namespace std;

class person
{
protected:
    string name;

public:
    void introduce()
    {
        cout << "Hello is my name is  " << name << endl;
    }
};

class Employeee : public person
{
protected:
    int salary;

public:
    void monthly_salary()
    {
        cout << "Helllo my mnthly salary is " << salary << endl;
    }
};

class manager : public Employeee
{
public:
    string department;
    manager(string name, int salary, string department)
    {
        this->name = name;
        this->salary = salary;
        this->department = department;
    }


};

int main()
{
    manager a1("dev", 5421, "devops");
    // a1.introduce();
    // a1.monthly_salary(); 
    // person a2;
    // a2.introduce();
    return 0;
}