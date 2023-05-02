#include<stdio.h> 
void swap(int *a, int *b)
{
    int temp= *a;
    *a=*b;
    *b=temp;
}

 
void bubbleSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int flag=0;
        for(int J=0;J<n-1-i;J++)
        {
            if(a[J]>a[J+1]){
            swap(&a[J],&a[J+1]);
            flag=1;
            }
        }
        if(flag==0)
        break;
    }
}

int main()
{
    int n;
    printf("Enter the size of array :");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array  ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubbleSort(a,n);
    printf("Elements of array after sorting are : ");

    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}