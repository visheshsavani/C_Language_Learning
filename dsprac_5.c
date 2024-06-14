#include<stdio.h>
#include<stdlib.h>
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
int evaluatetopostfix(char *exp){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));
    int i=0;
    int a,b;
    //int a1,b1;
    int res;
    while(exp[i]!='\0'){
        a=0;
        b=0;
      //  a1=0;
        //b1=0;
        res=0;
    if(exp[i]!='+' && exp[i]!='-' && exp[i]!='*' && exp[i]!='/' && exp[i]!='%'){
        push(sp,exp[i] - '0');
        i++;
    }
    else{
        a=pop(sp);
            b=pop(sp);
        switch(exp[i]){
        case '+':
            res=b+a;
            push(sp,res);
            i++;
            break;  
            case '-':
            //a=pop(sp);
            //b=pop(sp);
            res=b-a;
            push(sp,res);
             i++;
            break;
            case '*':
          //  a=pop(sp);
           // b=pop(sp);
            res=b*a;
            push(sp,res);
             i++;
            break;
            case '/':
           // a=pop(sp);
            //b=pop(sp);
            res=b/a;
            push(sp,res);
             i++;
            break;
            case '%':
           // a=pop(sp);
            //b=pop(sp);
            res=b%a;
            push(sp,res);
             i++;
            break;
        }
    }
    }
    return pop(sp);
}

int main(){
    char *exp="53+62/*35*+";
    printf("The postfix evaluation is %d\n",evaluatetopostfix(exp));
    return 0;
}