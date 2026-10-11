#include <iostream>
using namespace std;
#include <queue>
void disply(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main()
{

    queue<int> q;
    int arr[] = {2, 3, 9, 5, 6, 2};
    int n = 6;
    int k = 3;
    for (int i = 0; i < k - 1; i++)
    {
        q.push(arr[i]);
    }
    for (int i = k - 1; i < n; i++)
    {
        q.push(arr[i]);
        disply(q);
        q.pop();
    }
    return 0;
}