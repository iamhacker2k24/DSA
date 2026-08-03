#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(5);
    s.push(85);
    cout << s.size();
    cout << s.top();
    return 0;
}