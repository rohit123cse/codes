#include<stdio.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int a[],int l,int u)
{
    int pivot=a[l];
    int i=l,j=u;
    do{
    do{i++;}while(a[i]<=pivot);
    do{j--;}while(a[j]>pivot);
     if(i<j)
        swap(&a[i],&a[j]);
    }while(i<j);
   swap(&a[l],&a[j]);
   return j;
}
void quickSort(int a[ ],int l,int u)
{
    int mid;
    if(l<u)
    {
        mid=partition(a,l,u);
        quickSort(a,l,mid-1);
        quickSort(a,mid+1,u);
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

    quickSort(a,0,n);
    printf("Elements after sorting is : ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
