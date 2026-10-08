#include <iostream>
using namespace std;

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
class queue
{
    Node *front;
    Node *rear;

public:
    queue()
    {
        front = rear = NULL;
    }
    // Queue
    bool IsEmpty()
    {

        return front == NULL;
    }
    void push(int x)
    {
        // empty

        if (IsEmpty())
        {
            cout << "pushed " << x << " into the queue" << endl;
            front = rear = new Node(x);
            return;
        }

        rear->next = new Node(x);
        rear = rear->next;
        cout << "pushed " << x << " into the queue" << endl;

        // not empty
    }
    void pop()
    {
        /// empty to neihi hai na
        if (IsEmpty())
        {
            cout << "Queue underflow";
            return;
        }
        else
        {
            cout << "popped " << front->data << " from the queue";
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
    int start()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
            return front->data;
    }
};
int main()
{
    queue q;
    q.push(5);

    q.push(74);
    q.push(5);
    q.push(5);
    q.push(5);
    q.pop();
    cout << q.start() << endl;
    return 0;
}
