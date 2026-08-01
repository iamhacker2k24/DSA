#include <iostream>
using namespace std;

// stack using arry
class stack
{

    int *arr;
    int top;
    int size;

public:
    stack(int s)
    {
        top = -1;
        arr = new int[s];
        size = s;
    }
    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "stack is overflow " << endl;
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "stack is under flow" << endl;
        }
        else
        {
            top--;
            cout << "valu poped sussfully" << endl;
        }
    }
    // peek is retun top value
    int peek()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return false ;
        }
        return true;
    }
    int isSize()
    {
        return top + 1;
    }
};
int main()
{

    stack s(3);
    s.push(-1);
    s.push(4);
    s.push(-1);

    // s.pop();
    if (s.isEmpty())
    {
        cout << s.peek() << endl;
    }

    // cout << s.isSize() << endl;

    return 0;
}