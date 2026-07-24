#include <iostream>
using namespace std;

// student
// boy
// girl
// male
// female
class student
{
public:
    void print()
    {
        cout << "I am student \n";
    }
};

class male
{
public:
    void maleprint()
    {
        cout << "i am male" << endl;
    }
};

class girl
{
public:
    void girlprint()
    {
        cout << "i am girl" << endl;
    }
};

class boy : public student, public male
{
public:
    void Boyprint()
    {
        cout << "I am a boy";
    }
};
class female : public student, public girl
{
public:
    void Boyprint()
    {
        cout << "I am a female";
    }
};

int main()
{
    girl g1;
    g1.girlprint();
    boy b11;
    b11.Boyprint();
    return 0;
}