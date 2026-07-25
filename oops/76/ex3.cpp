// why need to use throw thou we have if else

#include <iostream>
#include <exception>
using namespace std;
class exception
{

   protected:
   string msg;

public:
    exception(string msg)
    {
        this->msg = msg;
    }
    string what(){
        return msg;
    }
};

int main()
{
    try
    {
        int *p = new int[1000000000000000];
        cout << "allocated ";
        delete[] p;
    }
    catch (const bad_alloc &e)
    {
        cout << "exception occur " << e.what() << endl;
    }
}