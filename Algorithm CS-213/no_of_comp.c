#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int N;
    printf("Enter The no of arrays : ");
    scanf("%d", &N);
    printf("Enter the sizes : ");
    int arr[N];
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    // from last
    // for (int i = N - 1; i > 0; i--)
    // {
    //     printf("%d-%d", arr[i], arr[i - 1]);
    //     int val = arr[i] + arr[i - 1] - 1;
    //     count += val;
    //     arr[i - 1] += arr[i];
    //     printf(":%d ", count);
    // }
    for (int i = 0; i < N - 1; i++)
    {
        insertionSort(arr, N);
        printf("%d-%d", arr[i], arr[i + 1]);
        int val = arr[i] + arr[i + 1] - 1;
        count += val;
        arr[i + 1] += arr[i];
        arr[i] = 0;
        printf(":%d\n", count);
    }
    printf("Resultant value : %d", count);

    return 0;
}