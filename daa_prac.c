    #include <stdio.h>
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
        int arr[] = {299,70,340,90,1};
        int n = sizeof(arr)/sizeof(arr[0]);
        printf("The array before sorting\n");
        for(int i =0 ;i<n;i++){
            printf("%d ",arr[i]);
        }
        insertion_sort(arr,n);
        printf("\n");
        printf("The array after sorting\n");
        for(int i =0 ;i<n;i++){
            printf("%d ",arr[i]);
        }
        return 0;
    }