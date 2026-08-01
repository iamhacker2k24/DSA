/*
Program: Bubble Sort Algorithm
Language: C

Example Test Case

Input:
Enter number of elements: 6
Enter elements:
64 34 25 12 22 11

Output:
Sorted array:
11 12 22 25 34 64

----------------------------------

Input:
Enter number of elements: 5
Enter elements:
5 4 3 2 1

Output:
Sorted array:
1 2 3 4 5
*/

#include <stdio.h>

int main()
{
    int n, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}