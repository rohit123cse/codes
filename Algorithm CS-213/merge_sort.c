#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r)
{
    int i, j;
    int n1 = m - l + 1;
    int n2 = r - m;
    int a[n1], b[n2];

    int k;
    for (i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (j = 0; j < n1; j++)
    {
        b[j] = arr[m + j + 1];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = b[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = a[i++];
    }
    while (i < n2)
    {
        arr[k++] = b[j++];
    }
}
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{

    int n;
    printf("Enter the length of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    printf("Sorted array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}