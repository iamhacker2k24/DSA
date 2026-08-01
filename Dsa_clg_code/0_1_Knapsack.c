/*
Program: 0/1 Knapsack Problem using Dynamic Programming
Language: C

Example Test Case

Input:
Enter number of items: 4

Enter the weights:
1 3 4 5

Enter the profits:
1 4 5 7

Enter knapsack capacity: 7

Output:
Maximum Profit = 9

----------------------------------

Explanation:
Items:
Weight  Profit
1       1
3       4
4       5
5       7

Optimal Selection:
Weight = 3 + 4 = 7
Profit = 4 + 5 = 9
*/

#include <stdio.h>

#define MAX 100

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[MAX], profit[MAX];

    printf("Enter the weights:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }

    printf("Enter the profits:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &profit[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int dp[MAX][MAX];

    // Initialize first row and column
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    // Fill DP table
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= W; j++)
        {
            if(weight[i - 1] <= j)
            {
                dp[i][j] = max(
                    profit[i - 1] + dp[i - 1][j - weight[i - 1]],
                    dp[i - 1][j]
                );
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    printf("\nMaximum Profit = %d\n", dp[n][W]);

    return 0;
}