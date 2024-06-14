#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
int size;
int top;
int *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack *ptr,int i){
    int position = ptr->top - i +1;
    if(position<0){
        printf("Invalid position");
        return -1;
    }
    else{
        return ptr->arr[position];
    }
}
void display(struct stack *ptr){
 for (int j = 1; j <= ptr->top+1; j++)
    {
        printf("The value at position %d is %d\n",j,peek(ptr,j));
    }   
} 
int evaluatetoprefix(char *exp){
struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
sp->size=100;
sp->top=-1;
sp->arr=(int *)malloc(sp->size*sizeof(int));
int b;
int a;
int k=strlen(exp);
int res;
int i=k-1;
for(i;i>=0;i--){
    if(exp[i]!='+' && exp[i]!='-' && exp[i]!='*' && exp[i]!='/' && exp[i]!='%'){
        push(sp,exp[i] - '0');
    }
    else{
               b=pop(sp);
            a=pop(sp);
        switch(exp[i]){
        case '+':
            res=b+a;
            push(sp,res);
            
            break;  
            case '-':
            res=b-a;
            push(sp,res);
            
            break;
            case '*':
            res=b*a;
            push(sp,res);
             
            break;
            case '/':
            res=b/a;
            push(sp,res);
            break;
            case '%':
            res=b%a;
            push(sp,res);
            break;
        }
    }
}
return pop(sp);
}
int main(){
    char *prefix="+-+5/32*468";
    printf("The prefix evaluation is %d\n",evaluatetoprefix(prefix));
    return 0;
}