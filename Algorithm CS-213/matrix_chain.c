#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int matrixChainMultiplication(int *p, int n)
{
    int m[n][n];
    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }
    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n - 1];
}

int main()
{
    int n;
    printf("Enter the no. of matrices: ");
    scanf("%d", &n);
    int p[n + 1];
    printf("Enter the dimension:\n");
    for (int i = 0; i <= n; i++)
    {
        printf("P%d: ", i);
        scanf("%d", &p[i]);
    }
    int minMult = matrixChainMultiplication(p, n + 1);
    printf("Minimum number of multiplications is %d\n", minMult);
    return 0;
}
