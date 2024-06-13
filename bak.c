#include<stdio.h>
void insert_sort(int arr[],int n){
int i,j,key;
for (int i = 1; i < n; i++)
{
    key = arr[i];
    j = i-1;
    while(j>=0 && arr[j]>key){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}
}
void insertion_sort(int arr[],int n){
        int i,key,j;
        for ( i = 1; i < n; i++)
        {
            key = arr[i];
            j = i-1;
            while(j>=0 && arr[j]>key){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
int main(){
    int arr[] = {8,2,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    insert_sort(arr,n);
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }

}