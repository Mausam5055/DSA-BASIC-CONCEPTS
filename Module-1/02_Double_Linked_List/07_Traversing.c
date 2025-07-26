#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Head pointer to the start of the list
struct node *head = NULL;

// Function to display the list from beginning to end
void display() {
    struct node *ptr;
    ptr = head;

    // Check if list is empty
    if (ptr == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nPrinting values...\n");
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
