#include <iostream>
using namespace std;
#include <deque>
int main()
{
    deque<int> d;
    d.push_back(10);
    d.push_front(50);
    cout << d.front() << endl;
    cout << d.back() << endl;
    return 0;
}