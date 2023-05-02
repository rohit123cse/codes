#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionSort(int a[],int n)
{
    int i,j,k;
    for( i=0;i<n-1;i++)
    {
        for( j=k=i;j<n;j++)
        {
            if(a[j]<a[k])
            k=j;
        }
       swap(&a[i],&a[k]);
    }
}
int main()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array : ");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);

    selectionSort(a,n);
    printf("Elements of array after sorting is : ");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}