#include <stdio.h>
#include <limits.h>

int matrixChainMultiplication(int p[], int n)
{
    int DP[n][n];
    int i, j, k, L, q;

    // Setting the diagonal elements to zero.
    for (i = 1; i < n; i++)
    {
        DP[i][i] = 0;
    }

    // Solving for chain length 'L' (from 2 to n).
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            DP[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = DP[i][k] + DP[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < DP[i][j])
                {
                    DP[i][j] = q;
                }
            }
        }
    }

    // The final answer is stored in DP[1][n-1].
    return DP[1][n - 1];
}

int main()
{
    int N;
    printf("Enter the number of matrices to be multiplied : ");
    scanf("%d", &N);

    int dimensionArray[N + 1];
    printf("Enter the dimensions of all the matrices : ");
    for (int i = 0; i <= N; i++)
    {
        scanf("%d", &dimensionArray[i]);
    }

    int minMultiplicationsReq = matrixChainMultiplication(dimensionArray, N + 1);
    printf("The minimum number of multiplications required to compute the chain of matrices is: %d", minMultiplicationsReq);

    return 0;
}