#include<stdio.h>

void merge(int a[],int l,int h,int mid)
{
    int i=l,j=mid+1,k=l;
    int b[100];
    while(i<=mid&&j<=h)
    {
        if(a[i]>a[j])
    b[k++]=a[j++];
    else
    b[k++]=a[i++];
    }

    for(;i<=mid;i++)
    b[k++]=a[i];

    for(;i<=h;i++)
    b[k++]=a[j];

    for(int i=l;i<=h;i++)
    a[i]=b[i];

}


void mergeSort(int a[],int l,int h)
{
    int mid=(l+h)/2;
    if(l<h)
    {
        
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,h);
    merge(a,l,h,mid);
    }
}
int main()
{
    // int a[10]={23,3,4,56,4,300,23,55,6,45};
    int n;
    printf("Enter the size of array ; ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array: ");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    // mergeSort(a,0,9);
    mergeSort(a,0,n-1);
    printf("Elements of array after sorting is : ");
    // for(int i=0;i<10;i++)
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}