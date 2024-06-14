#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

// Create a new node and return a pointer to it
Node* create_node(int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->val = val;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node with 'val' at the specified position
void insert_at_pos(Node** header, Node** trailer, int val, int pos, bool is_after) {
    Node* new_node = create_node(val);

    if (pos == 0 && is_after) {
        new_node->next = (*header)->next;
        new_node->prev = *header;
        if ((*header)->next != NULL) {
            (*header)->next->prev = new_node;
        }
        (*header)->next = new_node;
    } else if (pos == -1 && !is_after) {
        new_node->prev = (*trailer)->prev;
        new_node->next = *trailer;
        if ((*trailer)->prev != NULL) {
            (*trailer)->prev->next = new_node;
        }
        (*trailer)->prev = new_node;
    } else {
        Node* current = (*header)->next;
        int current_pos = 0;

        while (current != *trailer && current_pos != pos) {
            current = current->next;
            current_pos++;
        }

        if (current == *trailer && is_after) {
            fprintf(stderr, "Position %d is out of bounds for insertion\n", pos);
            free(new_node);
            return;
        }

        if (is_after) {
            new_node->prev = current;
            new_node->next = current->next;
            current->next = new_node;
            new_node->next->prev = new_node;
        } else {
            new_node->prev = current->prev;
            new_node->next = current;
            current->prev = new_node;
            new_node->prev->next = new_node;
        }
    }
}

// Delete a node at the specified position
void delete_at_pos(Node** header, Node** trailer, int pos) {
    if (pos == 0) {
        fprintf(stderr, "Cannot delete the header node\n");
        return;
    }

    Node* current = (*header)->next;
    int current_pos = 0;

    while (current != *trailer && current_pos != pos) {
        current = current->next;
        current_pos++;
    }

    if (current == *trailer) {
        fprintf(stderr, "Position %d is out of bounds for deletion\n", pos);
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}

// Reverse the doubly linked list
void reverse(Node **header) {
    Node *temp = NULL;
    Node *current = *header;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *header = temp->prev;
    } else {
        *header = current;
    }
}

// Swap nodes at two specified positions
void swap(Node** header, Node** trailer, int pos_1, int pos_2) {
    if (pos_1 == pos_2) {
        return; // No need to swap if the positions are the same.
    }

    Node* node_1 = (*header)->next;
    int current_pos = 0;

    while (node_1 != *trailer && current_pos != pos_1) {
        node_1 = node_1->next;
        current_pos++;
    }

    Node* node_2 = (*header)->next;
    current_pos = 0;

    while (node_2 != *trailer && current_pos != pos_2) {
        node_2 = node_2->next;
        current_pos++;
    }

    if (node_1 == *trailer || node_2 == *trailer) {
        fprintf(stderr, "One or both positions are out of bounds for swapping\n");
        return;
    }

    // Swap the nodes
    if (node_1->prev != NULL) {
        node_1->prev->next = node_2;
    } else {
        (*header)->next = node_2;
    }

    if (node_2->prev != NULL) {
        node_2->prev->next = node_1;
    } else {
        (*header)->next = node_1;
    }

    Node* temp_prev = node_1->prev;
    node_1->prev = node_2->prev;
    node_2->prev = temp_prev;

    Node* temp_next = node_1->next;
    node_1->next = node_2->next;
    node_2->next = temp_next;
}

// Display the elements of the doubly linked list
void display(Node* header, Node* trailer) {
    Node* current = header->next;

    printf("Doubly Linked List: ");
    while (current != trailer) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* header = create_node(-1); // Dummy header node
    Node* trailer = create_node(-1); // Dummy trailer node
    header->next = trailer;
    trailer->prev = header;

    // Insert elements
    insert_at_pos(&header, &trailer, 78, 0, true); 
    insert_at_pos(&header, &trailer, 22, 0, true); 
    insert_at_pos(&header, &trailer, 37, 0, true);
    insert_at_pos(&header, &trailer, 46, 0, true);
    insert_at_pos(&header, &trailer, 4, 0, true);
     

    display(header, trailer);
    //reverse(&header);
    swap(&header, &trailer, 0, 2);
    printf("Doubly linked list after swapping");
    printf("\n");
    display(header, trailer);
    delete_at_pos(&header,&trailer,3);
    //printf("Doubly linked list after deletion of node");
    ///printf("\n");
    ///display(header, trailer);
    // Free memory and return
    free(header);
    free(trailer);
    return 0;
}
