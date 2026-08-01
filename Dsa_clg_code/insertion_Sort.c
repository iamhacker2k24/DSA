/*
Program: Insertion Sort Algorithm
Language: C

Example Test Case

Input:
Enter number of elements: 6
Enter elements:
12 11 13 5 6 7

Output:
Sorted array:
5 6 7 11 12 13

----------------------------------

Input:
Enter number of elements: 5
Enter elements:
9 4 7 2 8

Output:
Sorted array:
2 4 7 8 9
*/

#include <stdio.h>

int main()
{
    int n, i, j, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Insertion Sort
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}