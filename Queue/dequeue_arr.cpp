#include <iostream>
using namespace std;
class Dequeue
{
    int front, rear, size;
    int *arr;

public:
    Dequeue(int n)
    {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }
    bool IsEmpty()
    {
        return front == -1;
    }
    bool IsFull()
    {
        return (rear + 1) % size == front;
    }
    void push_front(int x)
    {
        // Empty
        if (IsEmpty())
        {
            cout << "pushed " << x << " in front " << endl;
            front = rear = 0;
            arr[0] = x;
            return;
        }
        // full
        else if (IsFull())
        {
            cout << " dequew oveflow" << endl;
            return;
        }
        // normal
        else
        {
            front = (front - 1 + size) % size;
            arr[front] = x;
            cout << "Pushed " << x << " in front" << endl;
            return;
        }
    }
    void push_back(int x)
    {
        // Empty
        if (IsEmpty())
        {
            cout << "pushed " << x << " in front " << endl;
            front = rear = 0;
            arr[0] = x;
            return;
        }
        // full
        else if (IsFull())
        {
            cout << " dequew oveflow" << endl;
            return;
        }
        // normal
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
            cout << "Pushed " << x << " in front" << endl;
            return;
        }
    }
    void pop_front()
    {
        // empty
        if (IsEmpty())
        {
            cout << " Dequew underflow " << endl;
            return;
        }
        else
        {
            // single element
            if (front == rear)
            {
                cout << "poped" << arr[front] << "from deque " << endl;
                ;
                front = rear = -1;
            }
            // greater than 1 element
            else
            {
                front = (front + 1) % size;
            }
        }
    }
    void pop_back()
    {
        // empty
        if (IsEmpty())
        {
            cout << " Dequew under flow " << endl;
            return;
        }
        else
        {
            cout << "poped" << arr[front] << "from deque " << endl;
            // single element
            if (front == rear)
            {
                front = rear = -1;
            }
            // greater than 1 element
            else
            {
                rear = (rear - 1 + size) % size;
            }
        }
    }
    int start()
    {
        if (IsEmpty())
            return -1;
        else
            cout << "Start is " << arr[front] << endl;
        return arr[front];
    }
    int end()
    {
        if (IsEmpty())
            return -1;
        else
            cout << "end is " << arr[front] << endl;

        return arr[rear];
    }
};
int main()
{
    Dequeue d(5);
    d.push_back(41);
    d.push_back(41);
    d.push_back(41);
    d.push_back(41);
    d.push_back(41);
    // d.push_back(41);
    d.pop_front();
    d.start();
    return 0;
}