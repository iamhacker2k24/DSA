/*
Program: Randomized Quick Sort using Divide and Conquer
Language: C

Example Test Case

Input:
Enter number of elements: 7
Enter elements:
10 7 8 9 1 5 3

Output:
Sorted array:
1 3 5 7 8 9 10

----------------------------------

Input:
Enter number of elements: 5
Enter elements:
50 20 40 10 30

Output:
Sorted array:
10 20 30 40 50
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

// Select a random pivot
int randomPartition(int arr[], int low, int high)
{
    int random = low + rand() % (high - low + 1);

    swap(&arr[random], &arr[high]);

    return partition(arr, low, high);
}

// Randomized Quick Sort
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = randomPartition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Seed the random number generator
    srand(time(NULL));

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}