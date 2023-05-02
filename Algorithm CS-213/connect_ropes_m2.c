#include <stdio.h>
void max_heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        max_heapify(arr, n, largest);
    }
}
void heapsort(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        max_heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        max_heapify(arr, i, 0);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    heapsort(a, n);
    int cost = 0;
    while (n > 1)
    {

        int min1 = a[0];
        int min2 = a[1];
        int sum = min1 + min2;
        cost += sum;
        a[0] = sum;
        a[1] = a[n - 1];

        n--;
        heapsort(a, n);
    }
    printf("%d", cost);
}