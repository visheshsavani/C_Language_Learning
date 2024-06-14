#include<stdio.h>
#include<stdlib.h>
struct node{
int coeff;
int expo;
struct node *next;
};
struct node *createterm(int c,int e){
    struct node *a = (struct node *)malloc(sizeof(struct node));
    a->coeff=c;
    a->expo=e;
    a->next=NULL;
    return a;
}
struct node *addterm(struct node *poly,int c,int e){
    struct node *term=createterm(c,e);
    if(poly==NULL){
        poly=term;
    }
    else{
        struct node *current = poly;
        while(current->next!=NULL){
            current= current->next;
        }
        current->next=term;
    }
    return poly;
}
void display(struct node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->expo);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}
struct node *multiply(struct node *poly1,struct node *poly2){
    if(poly1==NULL || poly2==NULL){
        return NULL;
    }
    
    struct node *result=NULL;
    struct node *temppoly2=poly2;
    while(poly1!=NULL){
        poly2=temppoly2;
        while(poly2!=NULL){
            int coeff= poly1->coeff * poly2->coeff;
            int expo = poly1->expo + poly2->expo;
            result = addterm(result,coeff,expo);
            poly2=poly2->next;
        }
        poly1=poly1->next;
    }
    return result;
}
int main(){
    struct node *poly1=NULL;
    struct node *poly2=NULL;
    poly1=  addterm(poly1,6,2);
    poly1 = addterm(poly1, 5, 3);
    poly1 = addterm(poly1, -2, 2);
  //  poly1 = addTerm(poly1, 3, 0);

    // Adding terms to the second polynomial
   poly2 = addterm(poly2, 3, 4);
    poly2 = addterm(poly2, 1, 2);
    poly2 = addterm(poly2, -7, 1);

    printf("First polynomial: ");
    display(poly1);

   printf("Second polynomial: ");
    display(poly2);

   struct node *result = multiply(poly1, poly2);
    printf("Resultant polynomial after multiplication: ");
    display(result);
return 0;
}