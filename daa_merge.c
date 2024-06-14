#include<stdio.h>
void merge(int arr[],int l,int r,int m){
    int i,j,k;
    i =0;
    j =0;
    k =l;
    int n1= m-l+1;
    int n2 = r -m;
    int L[n1],R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l+i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m+1+j];
    }
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] =L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] =R[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int l,int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,r,m);
        }
}
int main(){
    int arr[]= {3,3,3,2,1,1,8,9,9,9,9};
    int n;
    n = sizeof(arr)/sizeof(arr[0]); // size
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    mergesort(arr,0,n-1);
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
