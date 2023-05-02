#include<stdio.h>

void insertionSort(int a[],int n)
{
    int j;
        for(int i=1;i<n;i++)
        {
            int x=a[i];
            for( j=i-1;j>-1&&a[j]>x;j--)
            {
                a[j+1]=a[j];
            }
            a[j+1]=x;
        }
}

int main()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array : ");

    for(int i=0;i<n; i++)
    scanf("%d",&a[i]);

    insertionSort(a,n);
    printf("Elements of array after sorting is : ");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}
