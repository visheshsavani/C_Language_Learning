#include <stdio.h>
#include <stdlib.h>
struct queue{
int size;
int f;
int r;
int *arr;
};
int isEmpty(struct queue *ptr){
    if(ptr->f==ptr->r){
        //printf("The queue is empty\n");
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct queue *ptr){
    if(ptr->r==ptr->size-1){
        //printf("The queue is full\n");
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct queue *ptr,int a){
    if(isFull(ptr)){
        printf("The queue is full\n");
    }
    else{
    ptr->r=ptr->r+1;
    ptr->arr[ptr->r]=a;
    }
}
int dequeue(struct queue *ptr){
    int x;
    if (isEmpty(ptr))
    {
        printf("The queue is empty\n");
        return -1;
    }
    else{
        ptr->f=ptr->f+1;
        x=ptr->arr[ptr->f];
    }
    return x;
    }
int display(struct queue *ptr){
//return ptr->arr[ptr->f+1];
while(ptr->f!=ptr->r){
    printf("%d ",ptr->arr[ptr->f+1]);
    ptr->f=ptr->f+1;
    
}
}
int main(){
    struct queue q;
    q.size=400;
    q.f=q.r=0;
    q.arr=(int *)malloc(q.size*sizeof(int));
    //bfs implementation
    int node;
    int i = 0;
    int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] ==1 && visited[j] == 0){
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}
