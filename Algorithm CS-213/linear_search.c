#include <stdio.h>

int main()
{
    int N;
    int arr[N];
    printf("Enter the length of array : ");
    scanf("%d", &N);
    printf("Enter the array : ");
    for (int i = 0; i < N; i++)
    {
        int get;
        scanf("%d", &get);
        arr[i] = get;
    }
    int val = 0;
    printf("Enter the value to be searched : ");
    scanf("%d", &val);
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == val)
        {
            printf("Entered Value is present at %d", i + 1);
            break;
        }
        else
        {
            if (i == N - 1)
            {
                printf("Entered value not present in array");
            }
        }
    }

    return 0;
}