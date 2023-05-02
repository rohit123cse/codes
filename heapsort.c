#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int arr[100], size;

void swap(int *a, int *b)
{
    int x = *a;
    *a = *b;
    *b = x;
}

void minHeapify(int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < size && arr[left] < arr[i])
    {
        smallest = left;
    }
    if (right < size && arr[right] < arr[i])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(arr + smallest, arr + i);
        minHeapify(smallest);
    }
}

void build_min_heap()
{
    for (int i = size / 2; i >= 0; i--)
    {
        minHeapify(i);
    }
}

int extract_min()
{
    int min = arr[0];
    arr[0] = arr[--size];
    minHeapify(0);
    return min;
}
void insert(int val)
{
    arr[size++] = val;
    minHeapify(0);
}

int main()
{
    size = 5;
    arr[0] = 5;
    arr[1] = 3;
    arr[2] = 1;
    arr[3] = 4;
    arr[4] = 5;
    build_min_heap();
    int temp[5];
    for (int i = 0; i < 5; i++)
    {
        temp[i] = extract_min();
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", temp[i]);
    }
}