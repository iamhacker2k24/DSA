/*
Program: Job Sequencing with Deadlines using Greedy Method
Language: C

Example Test Case

Input:
Enter number of jobs: 5

Enter Job ID, Deadline and Profit:
1 2 100
2 1 19
3 2 27
4 1 25
5 3 15

Output:
Selected Job Sequence:
1 3 5

Maximum Profit = 142

----------------------------------

Explanation:
Job 1 -> Deadline = 2, Profit = 100
Job 2 -> Deadline = 1, Profit = 19
Job 3 -> Deadline = 2, Profit = 27
Job 4 -> Deadline = 1, Profit = 25
Job 5 -> Deadline = 3, Profit = 15

Optimal Sequence:
Job 1
Job 3
Job 5

Total Profit = 100 + 27 + 15 = 142
*/

#include <stdio.h>

struct Job
{
    int id;
    int deadline;
    int profit;
};

// Sort jobs by profit (descending)
void sortJobs(struct Job jobs[], int n)
{
    int i, j;
    struct Job temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(jobs[i].profit < jobs[j].profit)
            {
                temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
}

int main()
{
    int n, i, j;
    int maxProfit = 0;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    printf("Enter Job ID, Deadline and Profit:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d %d %d",
              &jobs[i].id,
              &jobs[i].deadline,
              &jobs[i].profit);
    }

    // Sort jobs according to profit
    sortJobs(jobs, n);

    // Find maximum deadline
    int maxDeadline = 0;

    for(i = 0; i < n; i++)
    {
        if(jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    int slot[maxDeadline + 1];

    for(i = 0; i <= maxDeadline; i++)
        slot[i] = -1;

    // Schedule jobs
    for(i = 0; i < n; i++)
    {
        for(j = jobs[i].deadline; j > 0; j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = i;
                maxProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("\nSelected Job Sequence:\n");

    for(i = 1; i <= maxDeadline; i++)
    {
        if(slot[i] != -1)
        {
            printf("%d ", jobs[slot[i]].id);
        }
    }

    printf("\nMaximum Profit = %d\n", maxProfit);

    return 0;
}