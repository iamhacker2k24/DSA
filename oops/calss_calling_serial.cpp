#include <iostream>
using namespace std;
class calss_calling_serial
{
    int name;

public:
    calss_calling_serial()
    {
        name = 4;
        cout << "const a4" << endl;
    }
    calss_calling_serial(int num)
    {
        name = num;
        cout << "constructor" << name << endl;
    }
    ~calss_calling_serial() // caling reverse ordeer
    {

        cout << name << endl;
    }
};

int main()
{
    calss_calling_serial a(1), b(2), c(3);
    calss_calling_serial *a4 = new calss_calling_serial;
    delete a4;
    return 0;
}