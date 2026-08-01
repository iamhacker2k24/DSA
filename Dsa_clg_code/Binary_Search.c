/*
Program: Binary Search using Divide and Conquer
Language: C

Example Test Case

Input:
Enter number of elements: 6
Enter sorted elements:
10 20 30 40 50 60
Enter element to search: 40

Output:
Element found at position 4

----------------------------------

Input:
Enter number of elements: 5
Enter sorted elements:
5 10 15 20 25
Enter element to search: 18

Output:
Element not found
*/

#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key)
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearch(arr, left, mid - 1, key);

    return binarySearch(arr, mid + 1, right, key);
}

int main()
{
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Element found at position %d\n", result + 1);
    else
        printf("Element not found\n");

    return 0;
}