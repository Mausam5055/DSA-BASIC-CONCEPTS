#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Declare global head pointer
struct node *head = NULL;

// Function to delete from the beginning of the doubly linked list
void deletion_beginning() {
    struct node *ptr;

    // Check if list is empty
    if (head == NULL) {
        printf("\nUNDERFLOW - List is empty, nothing to delete.\n");
    }
    // If only one node exists
    else if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("\nNode deleted (only node in the list)\n");
    }
    // If more than one node
    else {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("\nNode deleted from beginning\n");
    }
}

// You can write main() to test it if needed
