#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for node in Huffman tree
typedef struct node
{
  char ch;
  int freq;
  struct node *left;
  struct node *right;
} node;

// Function to create a new node
node *newNode(char ch, int freq)
{
  node *new = (node *)malloc(sizeof(node));
  new->ch = ch;
  new->freq = freq;
  new->left = NULL;
  new->right = NULL;
  return new;
}

// Function to create a priority queue
void createPriorityQueue(node **queue, int *frequencies, char *characters, int size)
{
  for (int i = 0; i < size; i++)
  {
    queue[i] = newNode(characters[i], frequencies[i]);
  }
}

// Function to compare nodes for priority queue
int compareNodes(const void *a, const void *b)
{
  node **nodeA = (node **)a;
  node **nodeB = (node **)b;
  return (*nodeA)->freq - (*nodeB)->freq;
}

// Function to build the Huffman tree
node *buildHuffmanTree(node **queue, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    node *z = newNode('\0', 0);
    z->left = queue[0];
    z->right = queue[1];
    z->freq = queue[0]->freq + queue[1]->freq;
    queue[0] = z;
    for (int j = 1; j < size - i - 1; j++)
    {
      queue[j] = queue[j + 1];
    }
    qsort(queue, size - i - 1, sizeof(node *), compareNodes);
  }
  return queue[0];
}

// Function to print Huffman codes for each character
void printHuffmanCodes(node *root, char *code, int top)
{
  if (root->left)
  {
    code[top] = '0';
    printHuffmanCodes(root->left, code, top + 1);
  }
  if (root->right)
  {
    code[top] = '1';
    printHuffmanCodes(root->right, code, top + 1);
  }
  if (!root->left && !root->right)
  {
    printf("%c: ", root->ch);
    for (int i = 0; i < top; i++)
    {
      printf("%c", code[i]);
    }
    printf("\n");
  }
}

int main()
{
  // Read input
  int size;
  printf("Enter the size : ");
  scanf("%d", &size);
  char characters[size];
  int frequencies[size];
  printf("Enter the data\n");
  for (int i = 0; i < size; i++)
  {
    printf("Enter character and it's frequency --%d : ", i + 1);
    scanf(" %c %d", &characters[i], &frequencies[i]);
  }

  // Create priority queue and build Huffman tree
  node *queue[size];
  createPriorityQueue(queue, frequencies, characters, size);
  qsort(queue, size, sizeof(node *), compareNodes);
  node *root = buildHuffmanTree(queue, size);

  // Print Huffman codes for each character
  char code[size];
  printHuffmanCodes(root, code, 0);

  return 0;
}