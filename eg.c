#include <stdio.h>
#include <stdlib.h>

// Node structure for representing a term in a polynomial
typedef struct Node {
    int coeff;
    int exp;
    struct Node *next;
} Node;

// Function to create a new node with given coefficient and exponent
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to add a term to the polynomial represented by a linked list
Node* addTerm(Node* poly, int coeff, int exp) {
    Node* newTerm = createNode(coeff, exp);
    if (poly == NULL) {
        poly = newTerm;
    } else {
        Node* current = poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
    return poly;
}

// Function to multiply two polynomials represented by linked lists
Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    if (poly1 == NULL || poly2 == NULL) {
        return NULL;
    }

    Node* result = NULL;
    Node* tmpPoly2 = poly2;

    while (poly1 != NULL) {
        poly2 = tmpPoly2; // Reset poly2 to the start of the second polynomial for each term in poly1
        while (poly2 != NULL) {
            int coeff = poly1->coeff * poly2->coeff;
            int exp = poly1->exp + poly2->exp;
            // Add the term to the result polynomial
            result = addTerm(result, coeff, exp);
            poly2 = poly2->next;
        }
        poly1 = poly1->next;
    }
    return result;
}

// Function to display the polynomial
void display(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to free memory allocated for the linked list
void freeList(Node* poly) {
    Node* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    // Adding terms to the first polynomial
    poly1 = addTerm(poly1, 5, 3);
    poly1 = addTerm(poly1, -2, 2);
    poly1 = addTerm(poly1, 3, 0);

    // Adding terms to the second polynomial
    poly2 = addTerm(poly2, 3, 4);
    poly2 = addTerm(poly2, 1, 2);
    poly2 = addTerm(poly2, -7, 1);

    printf("First polynomial: ");
    display(poly1);

    printf("Second polynomial: ");
    display(poly2);

    Node* result = multiplyPolynomials(poly1, poly2);
    printf("Resultant polynomial after multiplication: ");
    display(result);

    // Free memory allocated for the linked lists
    freeList(poly1);
    freeList(poly2);
    freeList(result);

    return 0;
}
