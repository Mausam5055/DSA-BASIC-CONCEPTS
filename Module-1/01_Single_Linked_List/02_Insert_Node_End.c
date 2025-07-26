#include <stdio.h>
#include <stdlib.h>

// Function prototype for inserting a node at the end
void lastinsert(int);

// Define the structure of a node
struct node {
    int data;              // Data part of the node
    struct node *next;     // Pointer to the next node
};

// Global pointer to the head of the linked list
struct node *head = NULL;

void main() {
    int choice, item;

    // Loop to allow inserting multiple nodes
    do {
        printf("\nEnter the item which you want to insert:\n");
        scanf("%d", &item);          // Read the value to be inserted

        lastinsert(item);            // Call the function to insert at the end

        printf("\nPress 0 to insert more ?\n");
        scanf("%d", &choice);        // Continue inserting if user enters 0
    } while(choice == 0);
}

// Function to insert a node at the end of the linked list
void lastinsert(int item) {
    // Create a new node and allocate memory
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp;

    // Check if memory allocation failed
    if(ptr == NULL) {
        printf("\nOVERFLOW");        // Print overflow message if malloc fails
    } else {
        ptr->data = item;            // Assign data to the new node

        // Case 1: If the list is empty
        if(head == NULL) {
            ptr->next = NULL;        // New node will point to NULL
            head = ptr;              // Make it the first node (head)
            printf("\nNode inserted");
        }
        // Case 2: If the list is not empty
        else {
            temp = head;

            // Traverse the list to find the last node
            while(temp->next != NULL) {
                temp = temp->next;
            }

            // Insert the new node at the end
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nNode inserted");
        }
    }
}

// ■ Output
// Enter the item which you want to insert?
// 12

// Node inserted
// Press 0 to insert more ?
// 0

// Enter the item which you want to insert?
// 23

// Node inserted
// Press 0 to insert more ?
// 2