#include <stdio.h>
#include <stdlib.h>

struct MinHeapNode
{
    int data;
    struct MinHeapNode *left, *right;
};

struct MinHeapNode *newNode(int data)
{
    struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    return temp;
}

struct MinHeap
{
    int size;
    int capacity;
    struct MinHeapNode **array;
};

struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b)
{
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->data < minHeap->array[smallest]->data)
    {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->array[right]->data < minHeap->array[smallest]->data)
    {
        smallest = right;
    }
    if (smallest != idx)
    {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap *minHeap)
{
    return (minHeap->size == 1);
}

struct MinHeapNode *extractMin(struct MinHeap *minHeap)
{
    struct MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->data < minHeap->array[(i - 1) / 2]->data)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

int minCost(int arr[], int n)
{
    int i, cost = 0;
    struct MinHeap *minHeap = createMinHeap(n);
    for (i = 0; i < n; ++i)
    {
        insertMinHeap(minHeap, newNode(arr[i]));
    }

    while (!isSizeOne(minHeap))
    {
        struct MinHeapNode *left = extractMin(minHeap);
        struct MinHeapNode *right = extractMin(minHeap);
        int sum = left->data + right->data;
        cost += sum;
        insertMinHeap(minHeap, newNode(sum));
    }
    return cost;
}

int main()
{
    int N, arr[N];
    printf("Enter the size of array : ");
    scanf("%d", &N);
    printf("Enter he array : ");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Minimum cost for connecting ropes is : %d\n", minCost(arr, N));
    return 0;
}