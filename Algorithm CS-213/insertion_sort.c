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
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int arr1[n];
    int arr2[n];
    printf("enter the array : ");
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
    }
    // for (int i = 0; i < n; i++)
    // {

    // }
    insertionSort(arr1, n);
    int pos[n];
    for (int i = 0; i < n; i++)
    {
        //  int m=k[i];
        for (int j = 0; j < n; j++)
        {
            if (arr2[i] == arr1[j])
            {
                pos[i] = j;
            }
        }
    }
    printf("Result position : ");
    for (int i = 0; i < n; i++)
    {

        printf("%d ", pos[i]);
    }
}