#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *sp){
    if(sp->top==-1) return -1;
    else return 0;
}
int isFull(struct stack *sp){
    if(sp->top==(sp->size-1)) return -1;
    else return 0;
}
void push(struct stack *sp,char x){
    if(isFull(sp)){
        printf("The stack is full\n");
    }
    else{
        sp->top=sp->top+1;
        sp->arr[sp->top]=x;
    }
}
char pop(struct stack *sp){
    if(isEmpty(sp)){
        printf("The stack is empty\n");
        return -1;
    }
    else{
        char x = sp->arr[sp->top];
        sp->top=sp->top-1;
        return x;
    }
}
char top(struct stack *sp){
    return sp->arr[sp->top];
}
int getPrecedence(char a){
    if(a=='/' || a=='*') return 3;
    else if(a=='-' || a=='+') return 2;
    return 0;
}
int isOperator(char a){
    if(a=='+' || a=='-' || a=='/' || a=='*') return 1;
    return 0;
}
char *infixtopostfix(char *infix){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=20;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(getPrecedence(infix[i]) > getPrecedence(top(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
            while(!isEmpty(sp)){
                postfix[j]=pop(sp);
                j++;
            }
            postfix[j]='\0';
            return postfix;
}
int main(){
    char *infix="x-y/z-k*d";
    printf("The postfix expression is %s\n",infixtopostfix(infix));
    return 0;
}

