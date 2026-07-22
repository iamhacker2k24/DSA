#include <iostream>
using namespace std;
class coustomer
{
    string name;
    int *data;

public:
    coustomer(string name)
    {
        this->name = name;
        cout << "constractur"<< name << endl;
    }
    ~coustomer()
    {

        cout << name << endl;
    }
};

int main()
{
    // here we are cheking the order in which a1,a2,a3 is constructor and disstructor calling ok?

    coustomer a1("1"), a2("2"), a3("3");

    return 0;
}