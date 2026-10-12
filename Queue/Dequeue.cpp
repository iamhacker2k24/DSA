#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int value)
    {
        data = value;
        next = prev = NULL;
    }
};
class Dequeue
{
    Node *front, *rear;

public:
    Dequeue()
    {
        front = rear = NULL;
    }
    // push_front
    void push_front(int x)
    {
        // empty
        if (front == NULL)
        {
            front = rear = new Node(x);
            cout << "Pushed " << x << " in front of dequeue" << endl;
            return;
        }
        else
        {
            Node *temp = new Node(x);
            temp->next = front;
            front->prev = temp;
            front = temp;
            cout << "pushed " << x << " in front of dequue" << endl;
            return;
        }
    }
    // push_back
    void push_back(int x)
    {
        // empty
        if (front == NULL)
        {
            front = rear = new Node(x);
            cout << "Pushed " << x << " in back  of dequeue" << endl;
            return;
        }
        else
        {
            Node *temp = new Node(x);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            cout << "pushed " << x << " in back of dequue" << endl;
            return;
        }
    }

    // pop_front
    void pop_front()
    {
        if (front == NULL)
        {
            cout << " deque underflow ";
            return;
        }
        else
        {
            Node *temp = front;
            cout << " Poped from " << temp->data << " from front";
            front = front->next;
            delete temp;

            // greater than 1 node
            if (front)
            {
                front->prev = NULL;
            }
            // 1 node
            else
            {
                rear = NULL;
            }
        }
    }

    // pop_back
    void pop_back()
    {
        if (front == NULL)
        {
            cout << " deque underflow ";
            return;
        }
        else
        {
            Node *temp = rear;
            cout << "Poped from " << temp->data << " from back ";
            front = rear->prev;
            delete temp;

            // greater than 1 node
            if (rear)
            {
                rear->next = NULL;
            }
            // 1 node
            else
            {
                front = NULL;
            }
        }
    }

    // start
    int start()
    {
        if (front == NULL)
        {
            return -1;
        }
        else
        {
            return front->data;
        }
    }
    // end
    int end()
    {
        if (front == NULL)
        {
            return -1;
        }
        else
        {
            return rear->data;
        }
    }
};

int main()
{

    Dequeue d;
    d.push_back(5);
    d.push_front(8);

    cout << d.start() << endl;
    d.pop_back();
    return 0;
}