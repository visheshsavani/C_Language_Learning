/*
 * File: expression_tree_preorder.c
 * Author: Siddhartha Chandra
 * Email: siddhartha_chandra@spit.ac.in
 * Created: October 17, 2023
 * Description: Create an expression tree from a preorder traversal.
 *  Additionally, add function to evaluate a given expression tree
 */

#include "stack1.c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to perform an operation on 2 operands
float perform_operation(char op, float left, float right) {
    switch (op) {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        if (right != 0) {
            return left / right;
        } else {
            fprintf(stderr, "Error: Division by zero\n");
            exit(EXIT_FAILURE);
        }
    default:
        fprintf(stderr, "Error: Unknown operator %c\n", op);
        exit(EXIT_FAILURE);
    }
}

ExprTreeNode *create_node(OpType op_type, Data data) {
    ExprTreeNode *treenode = (ExprTreeNode *)malloc(sizeof(ExprTreeNode));
    treenode->type = op_type;
    treenode->left = NULL;
    treenode->right = NULL;
    treenode->data = data;
    return treenode;
}

ExprTreeNode *create_ET_from_prefix(char *prefix_expression) {
    ExprTreeNode *root = NULL;
    int length = strlen(prefix_expression);
    printf("> %d\n", length);
    Stack *stack = initialize_stack(length);
    Data data;
    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(prefix_expression[i])) {
            data.operation = prefix_expression[i];
            ExprTreeNode *a = pop(stack);
            ExprTreeNode *b = pop(stack);
            ExprTreeNode *c = create_node(OPERATOR, data);
            c->left = a;
            c->right = b;
            push(stack, c);
        } else {
            data.operand = prefix_expression[i] - '0';
            ExprTreeNode *c = create_node(OPERAND, data);
            push(stack, c);
        }
        display(stack);
    }
    root = pop(stack);
    free(stack);
    return root;
}

void InOrderDisplay(ExprTreeNode *root) {
    if (root != NULL) {
        InOrderDisplay(root->left);
        if (isOperator(root->data.operation)) {
            printf("%c ", root->data.operation);
        } else {
            printf("%.2f ", root->data.operand);
        }
        InOrderDisplay(root->right);
    }
}

void PrefixDisplay(ExprTreeNode *root) {
    if (root != NULL) {
        if (isOperator(root->data.operation)) {
            printf("%c ", root->data.operation);
        } else {
            printf("%.2f ", root->data.operand);
        }
        PrefixDisplay(root->left);
        PrefixDisplay(root->right);
    }
}

float evaluate_ET(ExprTreeNode *root) {
    if (root->left != NULL || root->right != NULL) {
        float ans = 0;
        float left = evaluate_ET(root->left);
        float right = evaluate_ET(root->right);
        char op = root->data.operation;
        if (isOperator(op)) {
            ans = perform_operation(op, left, right);
        }
        return ans;
    } else {
        return root->data.operand;
    }
}

void main() {
    char exp[] = "*+12-5/84";
    ExprTreeNode *root = create_ET_from_prefix(exp);
    InOrderDisplay(root);
    printf("\n");
    PrefixDisplay(root);
    printf("\n\n> ANS: %.3f", evaluate_ET(root));
}