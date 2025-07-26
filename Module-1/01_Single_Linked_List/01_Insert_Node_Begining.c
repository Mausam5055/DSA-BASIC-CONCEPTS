#include <stdio.h>
#include <stdlib.h>

// Function prototype to insert a node at the beginning
void beginsert(int);

// Define the structure of a node in the linked list
struct node {
    int data;              // Data part of the node
    struct node *next;     // Pointer to the next node
};

// Declare the head of the linked list as a global pointer
struct node *head = NULL;

void main() {
    int choice, item;

    // Loop to allow multiple insertions
    do {
        printf("\nEnter the item which you want to insert:\n");
        scanf("%d", &item);        // Take input from user
        beginsert(item);           // Call function to insert item

        printf("\nPress 0 to insert more:\n");
        scanf("%d", &choice);      // If user enters 0, loop will continue
    } while(choice == 0);
}

// Function to insert a node at the beginning of the linked list
void beginsert(int item) {
    // Allocate memory for new node
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    // Check if memory allocation failed
    if(ptr == NULL) {
        printf("\nOVERFLOW\n");    // Print error if memory not allocated
    } else {
        ptr->data = item;          // Assign data to new node
        ptr->next = head;          // New node's next points to old head
        head = ptr;                // Update head to new node
        printf("\nNode inserted\n");
    }
}
