#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *a){
    if(a->top==-1){ 
        printf("Stack is Empty\n");
        return 1;
        }
    else return 0;}
int isFull(struct stack *a){
    if(a->top==(a->size-1)) printf("Stack is Full\n");
    else return 0;
}
void push(struct stack *a,int b){
    if(isFull(a)) printf("Stack is overflow\n");
    else{
        a->top=a->top+1;
        a->arr[a->top]=b;
        printf("Push operation is successfull\n");
    }
}
int pop(struct stack *b){
    if(isEmpty(b)){
         printf("Stack is underflow\n");
    return -1;}
    else{
        int x;
        x= b->arr[b->top];
        b->top=(b->top-1);
        return x;
    }
}
int peek(struct stack *a,int i){
    int position = (a->top) - i +1;
    if(position < 0){
        printf("Invalid position\n");
        return -1;
    }
    return a->arr[position];
}
void display(struct stack *s){
    for (int i = 1; i <= s->top+1; i++)
    {
        printf("The element in stack is %d\n",peek(s,i));
    }
}
int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size*(sizeof(int)));
    push(s,8);
    push(s,9);
    push(s,10);
    push(s,4);
    push(s,2);
    printf("The element which is pop is %d\n",pop(s));
    display(s);
    return 0;
}

