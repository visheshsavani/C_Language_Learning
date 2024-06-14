#include <stdio.h>
void selection_sort(int arr[],int n){
    int min_ind;
    for(int i =0;i<n-1;i++){
        min_ind = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min_ind]){
                min_ind = j;
                int temp = arr[min_ind];
                arr[min_ind] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
int main(){
    /*
    int arr[] = {299,70,340,90,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("The array before sorting\n");
    for(int i =0 ;i<n;i++){
        printf("%d ",arr[i]);
    }
   // selection_sort(arr,n);
    printf("\n");
    printf("The array after sorting\n");
    for(int i =0 ;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;*/
    printf("hi ");
    return 0;
}