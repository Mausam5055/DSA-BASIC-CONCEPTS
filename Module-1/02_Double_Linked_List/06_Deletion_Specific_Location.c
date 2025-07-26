#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Declare head globally
struct node *head = NULL;

// Function to delete a node after a given value
void deletion_specified() {
    struct node *ptr, *temp;
    int val;

    // Ask the user for the reference value
    printf("\nEnter the data after which the node is to be deleted: ");
    scanf("%d", &val);

    ptr = head;

    // Traverse the list to find the node with value 'val'
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    // If value not found or it's the last node
    if (ptr == NULL || ptr->next == NULL) {
        printf("\nCan't delete — either value not found or no node after it.\n");
        return;
    }

    // Case: Node to delete is the last node
    if (ptr->next->next == NULL) {
        temp = ptr->next;
        ptr->next = NULL;
        free(temp);
    }
    // Case: Node to delete is in the middle
    else {
        temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
    }

    printf("\nNode deleted successfully.\n");
}
