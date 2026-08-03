#include <iostream>
using namespace std;
// stacl using linklist
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
class stack
{

    Node *top;
    int size; // actual size of stack
public:
    stack()
    {
        top = NULL;
        size = 0;
    }
    // push
    void push(int value)
    {
        Node *temp = new Node(value);
        if (temp == NULL)
        {
            cout << "stack overflow" << endl;
            return;
        }
        else
        {
            temp->next = top;
            top = temp;
            size++;
            cout << "pushed " << value << " into the stack \n";
        }
    }
    // pop
    void pop()
    {
        if (top == NULL)
        {
            cout << "stack underflow" << endl;
        }
        else
        {
            Node *temp = temp;
            cout << "pooped " << top->data << " from the stack";
            top = top->next;
            delete temp;
            size--;
        }
    }
    // peek
    int peek()
    {
        if (top == NULL)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        else
        {
            return top->data;
        }
    }
    // isEmpty
    bool isEmpty()
    {
        return top == NULL;
    }
    // isSize
    int isSize()
    {
        return size;
    }
};
int main()
{
    stack s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.pop();
    cout << "\n" << s.isSize() << endl;

    return 0;
}