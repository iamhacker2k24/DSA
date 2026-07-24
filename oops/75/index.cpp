#include <iostream>
using namespace std;

class Area
{
public:
    int calculateArea(int r) // circle
    {
        return 3.14 * r;
    }
    int calculateArea(int l, int b)
    {
        return l * b;
    }
};

int main()
{
    Area a1, a2;
    cout << a1.calculateArea(2)<<endl;
    cout << a1.calculateArea(2, 6);
    return 0;
}