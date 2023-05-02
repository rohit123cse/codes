#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int maxCoins(int *nums, int numsSize)
{
    int *balloons = (int *)malloc((numsSize + 2) * sizeof(int));
    memcpy(balloons + 1, nums, numsSize * sizeof(int));
    balloons[0] = balloons[numsSize + 1] = 1;

    int n = numsSize + 2;
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int len = 3; len <= n; len++)
    {
        for (int left = 0; left <= n - len; left++)
        {
            int right = left + len - 1;
            for (int i = left + 1; i < right; i++)
            {
                int curr = balloons[left] * balloons[i] * balloons[right];
                dp[left][right] = fmax(dp[left][right], curr + dp[left][i] + dp[i][right]);
            }
        }
    }

    int result = dp[0][n - 1];
    free(balloons);
    return result;
}

int main()
{
    int n;
    printf("Enter the number on ballons  : ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter ballons : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int max_coins = maxCoins(nums, n);
    printf("The maximum coins that can be obtained by bursting all the balloons is: %d\n", max_coins);
    return 0;
    // int result = maxCoins(nums, numsSize);
    // printf("Maximum coins collected: %d\n", result);
    // return 0;
}
