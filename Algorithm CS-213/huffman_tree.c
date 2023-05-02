#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 256

// Node structure for Huffman tree
struct Node
{
    char character;
    int frequency;
    struct Node *left, *right;
};

// Priority queue implementation
struct PriorityQueue
{
    int size;
    int capacity;
    struct Node **array;
};

// Create a new node with given character and frequency
struct Node *createNode(char character, int frequency)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Create a new priority queue
struct PriorityQueue *createPriorityQueue(int capacity)
{
    struct PriorityQueue *pq = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
    pq->size = 0;
    pq->capacity = capacity;
    pq->array = (struct Node **)malloc(pq->capacity * sizeof(struct Node *));
    return pq;
}

// Swap two nodes in priority queue
void swapNodes(struct Node **a, struct Node **b)
{
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}

// Add a node to priority queue
void enqueue(struct PriorityQueue *pq, struct Node *node)
{
    int i = pq->size;
    pq->size++;
    pq->array[i] = node;
    while (i > 0 && pq->array[i]->frequency < pq->array[(i - 1) / 2]->frequency)
    {
        swapNodes(&pq->array[i], &pq->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Remove and return the node with minimum frequency from priority queue
struct Node *dequeue(struct PriorityQueue *pq)
{
    struct Node *node = pq->array[0];
    pq->size--;
    pq->array[0] = pq->array[pq->size];
    int i = 0;
    while (2 * i + 1 < pq->size)
    {
        int j = 2 * i + 1;
        if (j + 1 < pq->size && pq->array[j + 1]->frequency < pq->array[j]->frequency)
        {
            j++;
        }
        if (pq->array[i]->frequency > pq->array[j]->frequency)
        {
            swapNodes(&pq->array[i], &pq->array[j]);
            i = j;
        }
        else
        {
            break;
        }
    }
    return node;
}

// Build Huffman tree from given characters and frequencies
struct Node *buildHuffmanTree(char characters[], int frequencies[], int size)
{
    struct PriorityQueue *pq = createPriorityQueue(size);
    for (int i = 0; i < size; i++)
    {
        enqueue(pq, createNode(characters[i], frequencies[i]));
    }
    while (pq->size > 1)
    {
        struct Node *left = dequeue(pq);
        struct Node *right = dequeue(pq);
        struct Node *parent = createNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        enqueue(pq, parent);
    }
    struct Node *root = dequeue(pq);
    free(pq);
    return root;
}

// Recursive function to print Huffman codes for each character
void printCodes(struct Node *root, char code[], int top)
{
    if (root->left != NULL)
    {
        code[top] = '0';
        printCodes(root->left, code, top + 1);
    }
    if (root->right != NULL)
    {
        code[top] = '1';
        printCodes(root->right, code, top + 1);
    }
    if (root->left == NULL && root->right == NULL)
    {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++)
        {
            printf("%c", code[i]);
        }
        printf("\n");
    }
}

// Function to print Huffman codes for each character in given list of characters and frequencies
void printHuffmanCodes(char characters[], int frequencies[], int size)
{
    struct Node *root = buildHuffmanTree(characters, frequencies, size);
    char code[MAX_CHARACTERS];
    memset(code, '\0', sizeof(code));
    printCodes(root, code, 0);
    free(root);
}

int main()
{
    char characters[MAX_CHARACTERS];
    int frequencies[MAX_CHARACTERS];
    int size;
    printf("Enter the number of characters: ");
    scanf("%d", &size);

    printf("Enter the characters: ");
    for (int i = 0; i < size; i++)
    {
        scanf(" %c", &characters[i]);
    }

    printf("Enter the frequencies: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &frequencies[i]);
    }

    printf("Huffman codes:\n");
    printHuffmanCodes(characters, frequencies, size);

    return 0;
}