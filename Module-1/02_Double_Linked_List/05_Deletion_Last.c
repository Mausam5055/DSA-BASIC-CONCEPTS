#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Declare the head pointer globally
struct node *head = NULL;

// Function to delete the last node from a doubly linked list
void deletion_last() {
    struct node *ptr;

    // Case 1: List is empty
    if (head == NULL) {
        printf("\nUNDERFLOW - List is empty.\n");
    }
    // Case 2: Only one node in the list
    else if (head->next == NULL) {
        free(head);      // Free the only node
        head = NULL;     // Set head to NULL
        printf("\nNode deleted (only node in the list).\n");
    }
    // Case 3: More than one node
    else {
        ptr = head;

        // Traverse to the last node
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        // Remove the last node
        ptr->prev->next = NULL;
        free(ptr);

        printf("\nNode deleted from the end.\n");
    }
}
