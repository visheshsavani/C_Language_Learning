#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
};

void push(struct Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void infixToPrefix(char infix[], char prefix[]) {
    struct Stack stack;
    stack.top = -1;
    char temp[MAX_SIZE];
    int j = 0;

    // Reverse the infix expression
    for (int i = strlen(infix) - 1; i >= 0; i--) {
        if (infix[i] == '(')
            temp[j++] = ')';
        else if (infix[i] == ')')
            temp[j++] = '(';
        else
            temp[j++] = infix[i];
    }
    temp[j] = '\0';

    j = 0;
    for (int i = 0; i < strlen(temp); i++) {
        if (temp[i] >= 'a' && temp[i] <= 'z')
            prefix[j++] = temp[i];
        else if (temp[i] == ')')
            push(&stack, temp[i]);
        else if (temp[i] == '(') {
            while (stack.top != -1 && stack.items[stack.top] != ')')
                prefix[j++] = pop(&stack);
            if (stack.top != -1 && stack.items[stack.top] == ')')
                pop(&stack);
        } else if (isOperator(temp[i])) {
            while (stack.top != -1 && precedence(stack.items[stack.top]) >= precedence(temp[i]))
                prefix[j++] = pop(&stack);
            push(&stack, temp[i]);
        }
    }

    while (stack.top != -1)
        prefix[j++] = pop(&stack);

    prefix[j] = '\0';

    // Reverse the prefix expression to get the final result
    int len = strlen(prefix);
    for (int i = 0; i < len / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[len - i - 1];
        prefix[len - i - 1] = temp;
    }
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
