/*
Program: Matrix Chain Multiplication using Dynamic Programming
Language: C

Example Test Case

Input:
Enter the number of matrices: 4
Enter the dimensions:
10 20 30 40 30

Output:
Minimum number of multiplications = 30000

----------------------------------

Explanation:
Matrices:
A1 = 10 x 20
A2 = 20 x 30
A3 = 30 x 40
A4 = 40 x 30

Optimal Parenthesization:
((A1A2)(A3A4))

Minimum Cost = 30000
*/

#include <stdio.h>

#define MAX 100
#define INF 999999999

int main()
{
    int n;

    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[MAX];

    printf("Enter the dimensions:\n");
    for(int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    int m[MAX][MAX];

    // Cost is zero when multiplying one matrix
    for(int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    // L = chain length
    for(int L = 2; L <= n; L++)
    {
        for(int i = 1; i <= n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INF;

            for(int k = i; k < j; k++)
            {
                int q = m[i][k] +
                        m[k + 1][j] +
                        p[i - 1] * p[k] * p[j];

                if(q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }

    printf("\nMinimum number of multiplications = %d\n", m[1][n]);

    return 0;
}