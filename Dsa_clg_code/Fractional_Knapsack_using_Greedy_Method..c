/*
Program: Fractional Knapsack using Greedy Method
Language: C

Example Test Case

Input:
Enter number of items: 3

Enter profit and weight of each item:
60 10
100 20
120 30

Enter knapsack capacity: 50

Output:
Maximum Profit = 240.00

----------------------------------

Explanation:
Items are chosen based on profit/weight ratio.

Item 1 -> 60/10 = 6
Item 2 -> 100/20 = 5
Item 3 -> 120/30 = 4

Take Item 1 (10kg)
Take Item 2 (20kg)
Take 20kg out of 30kg of Item 3

Profit = 60 + 100 + (20/30)*120
       = 240
*/

#include <stdio.h>

struct Item
{
    int profit;
    int weight;
    float ratio;
};

// Function to sort items by profit/weight ratio in descending order
void sortItems(struct Item items[], int n)
{
    int i, j;
    struct Item temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(items[i].ratio < items[j].ratio)
            {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main()
{
    int n, i;
    int capacity;
    float totalProfit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter profit and weight of each item:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items based on ratio
    sortItems(items, n);

    for(i = 0; i < n; i++)
    {
        if(capacity >= items[i].weight)
        {
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else
        {
            totalProfit += items[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}