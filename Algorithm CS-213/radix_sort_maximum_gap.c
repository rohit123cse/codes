#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
int max(int a, int b)
{

  if (a > b)
    return a;
  else
    return b;
}
int findMax(int arr[], int n)
{
  int max = -322768;
  int i;
  for (i = 0; i < n; i++)
  {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}
void Sort(int A[], int n)
{
  int i, j, max, *C;
  max = findMax(A, n);
  C = (int *)malloc(sizeof(int) * (max + 1));
  for (i = 0; i < max + 1; i++)
  {
    C[i] = 0;
  }
  for (i = 0; i < n; i++)
  {
    C[A[i]]++;
  }

  i = 0;
  j = 0;
  while (j < max + 1)
  {
    if (C[j] > 0)
    {
      A[i++] = j;
      C[j]--;
    }
    else
      j++;
  }
}
int maxSortedAdjacentDiff(int *arr, int n)
{

  Sort(arr, n);

  int ans = 0;

  int i = 0, j = 1;

  while (j != n)
  {

    int k = arr[j] - arr[i];

    ans = max(ans, k);

    i++, j++;
  }

  return ans;
}
int main()
{
  int n;

  printf("No of element : ");
  scanf("%d", &n);
  int a[n];
  printf("Enter the element : ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  int k = maxSortedAdjacentDiff(a, n);
  printf("The maximum diff is : %d ", k);
}