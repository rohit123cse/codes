#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int arr[100];

void counting_sort(int d,int n){
    int arr2[2];
    arr2[0] = 0;
    arr2[1] = 0;
    for(int i=0;i<n;i++){
        arr2[(arr[i]>>d)&1]++;
    }
    arr2[1] += arr2[0];
    int f_ans[n];
    for(int i=n-1;i>=0;i--){
        f_ans[arr2[(arr[i]>>d)&1]-1] = arr[i];
        arr2[(arr[i]>>d)&1]--;   
    }

    for(int i=0;i<n;i++){
        arr[i] = f_ans[i];
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<=10;i++){
        counting_sort(i,n);
    }

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}