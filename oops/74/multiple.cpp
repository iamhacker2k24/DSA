// multiple inherense
#include <iostream>
using namespace std;
class Engineer
{
public:
    string specilization;
    void work()
    {
        cout << " I have specialiazion" << specilization << endl;
    }
};
class youtuber
{
public:
    int suscriber;
    void contentcreator()
    {
        cout << "I have suscriber basd on " << suscriber << endl;
    }
};
class codeteacher : public Engineer, public youtuber
{
public:
    string name;
    codeteacher(string name, string specilization, int suscriber)
    {
        this->name = name;
        this->specilization = specilization;
        this->suscriber = suscriber;
    }
    void showcase()
    {
        cout << "my name is  " << name << endl;
        work();
        contentcreator();
    }
};
int main()
{
    codeteacher a1("rohit_sir", "cse", 200);
    a1.showcase();

    return 0;
}