#include <stdio.h>

void binary_search(int arr[], int s, int e, int val)
{
    int mid = (e + s) / 2;
    if (arr[mid] == val)
    {
        printf("Element found at %d", mid + 1);
        return;
    }
    if (s <= e)
    {
        if (arr[mid] > val)
        {
            binary_search(arr, s, mid - 1, val);
        }
        else
        {
            binary_search(arr, mid + 1, e, val);
        }
    }
    else
    {
        printf("Element Not found");
        return;
    }
}

void display(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main()
{
    int N;
    int arr[N];
    printf("Enter the length of array : ");
    scanf("%d", &N);

    // Taking array input
    printf("Enter the array : ");
    for (int k = 0; k < N; k++)
    {
        int get;
        scanf("%d", &get);
        arr[k] = get;
    }
    int val;
    display(arr, N);
    printf("\n");
    // sorting
    // Bubble sort
    bubbleSort(arr, N);
    display(arr, N);
    printf("\n");
    // search
    printf("Enter the value to be searched : ");
    scanf("%d", &val);
    binary_search(arr, 0, N, val);
    return 0;
}