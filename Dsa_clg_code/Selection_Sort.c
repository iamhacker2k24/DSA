/*
Program: Selection Sort Algorithm
Language: C

Example Test Case

Input:
Enter number of elements: 6
Enter elements:
64 25 12 22 11 90

Output:
Sorted array:
11 12 22 25 64 90

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
    int n, i, j, minIndex, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Selection Sort
    for(i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if(minIndex != i)
        {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
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