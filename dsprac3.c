#include <stdio.h>
#include <stdlib.h>
struct circularqueue{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct circularqueue *a){
if(a->f==a->r){
    printf("The queue is empty\n");
    return -1;
}
else return 0;
}
int isFull(struct circularqueue *a){
    if(a->r==(a->size-1)){
        printf("The queue is full\n");
        return -1;
    }
    else return 0;
}
void enqueue(struct circularqueue *a,int x){
    if(isFull(a)){
       printf("The enqueue operation can't be performed\n");
    }
    else{
        a->r=(a->r+1)%(a->size);
        a->arr[a->r]=x;
    }
}
int dequeue(struct circularqueue *a){
    int y;
    if(isEmpty(a)){
          printf("The enqueue operation can't be performed\n");
          return -1;
    }
    else{
        a->f=(a->f+1)%(a->size);
        y=a->arr[a->f];
        return y;
    }
}
int main(){
      struct circularqueue *b=(struct circularqueue *)malloc(sizeof(struct circularqueue));
      b->size=20;
      b->f=b->r=0;
      b->arr=(int *)malloc((b->size)*sizeof(int));
      enqueue(b,12);
      enqueue(b,13);
      enqueue(b,14);
      enqueue(b,15);
      enqueue(b,16);
      printf("The dequeue element is %d\n",dequeue(b));
    return 0;
}
