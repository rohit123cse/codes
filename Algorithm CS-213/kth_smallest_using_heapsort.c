#include <stdio.h>

void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
int main()
{
    int N, K, arr[N];
    printf("Enter the Length of the array: ");
    scanf("%d", &N);
    printf("Enter the array : ");
    for (int k = 0; k < N; k++)
    {
        int get;
        scanf("%d", &get);
        arr[k] = get;
    }
    printf("Enter the key : ");
    scanf("%d", &K);
    heapSort(arr, N);
    printf("The output : %d", arr[K - 1]);
    return 0;
}