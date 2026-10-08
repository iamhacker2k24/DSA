#include <iostream>
using namespace std;
// implement queue using array

class queue
{
    int *arr;
    int front, rear, size;

public:
    queue(int n)
    {
        arr = new int[n];
        size = n;
        front = rear = -1;
    }
    // if queue is empty or not

    bool isEmpty()
    {
        return front == -1;
    }

    // queue is Full or not

    bool isFull()
    {
        return rear == size - 1;
    }
    // push element
    void push(int x)
    {
        // empty
        if (isEmpty())
        {
            cout << "pushed x =" << x << endl;
            front = rear = 0;
            arr[0] = x;
        }
        // full
        if (isFull())
        {
            cout << "queue is full" << endl;
            return;
        }
        // insert
        else
        {
            rear = rear + 1;
            arr[rear] = x;
            cout << "pushed x =" << x << endl;
        }
    }
    // pop element
    void pop()
    {
        // empty
        if (isEmpty())
        {
            cout << "stack is underflow" << endl;
            return;
        }
        // pop kar do
        else
        {
            if (front == rear)
            {

                cout << "pop " << arr[front] << endl;
                front = rear = -1;
            }
            else
            {

                cout << "pop " << arr[front] << endl;
                front = front + 1;
            }
        }
    }

    int start()
    {
        if (isEmpty())
        {
            cout << "Queue is empty " << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};

int main()
{
    queue q(5);
    q.push(62);
    q.push(3);
    q.push(9);
    q.push(8);

    q.pop();

    q.pop();
    cout << q.start();

    return 0;
}