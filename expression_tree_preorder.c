/*
 * File: expression_tree_preorder.c
 * Author: Siddhartha Chandra
 * Email: siddhartha_chandra@spit.ac.in
 * Created: October 17, 2023
 * Description: Create an expression tree from a preorder traversal. 
 *  Additionally, add function to evaluate a given expression tree
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.c"


// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to perform an operation on 2 operands
float perform_operation(char op, float left, float right){
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


// TODO: To be completed
ExprTreeNode *create_node(OpType op_type, Data data){

}


// TODO: To be completed
// NOTE: Use the stack 'display' in this function to display stack state right after a given character in the expression has been processed.
// Do this for all characters of the expression string
ExprTreeNode *create_ET_from_prefix(char *prefix_expression){

}


// TODO: To be completed
float evaluate_ET(ExprTreeNode* root){
    
}
