#include<stdio.h>
int fibo();
int main(){
    int b,c;
    printf("Enter the value of b\n");
    scanf("%d",&b);
     c=fibo(b);
     //printf("The fibonacci term of %d is %d\n",b,c);
     for ( int i = 1; i <=b ; i++)
     {
        c=fibo(i);
        printf("%d ",c);
     }
     
    return 0;
}
int fibo(int a){
if(a==1){
    return 1;
}
else if(a==0){
    return 0;
}
else{
    return fibo(a-1) + fibo(a-2);
}
}