#include <stdio.h>
#include <stdlib.h>

// Function declarations
void create(int);       // Inserts node at the beginning
void begdelete();       // Deletes node from the beginning

// Node structure definition
struct node {
    int data;
    struct node *next;
};

// Global pointer to the head of the linked list
struct node *head;

void main() {
    int choice, item;

    // Menu-driven program
    do {
        // Menu options (NOTE: newline after 2 is incorrectly placed)
        printf("\n1.Append List\n2.Delete node\n3.Exit\n4.Enter your choice?");
        scanf("%d", &choice);  // Take user's choice

        switch(choice) {
            case 1:
                // Inserting node at beginning
                printf("\nEnter the item\n");
                scanf("%d", &item);
                create(item);  // Call insert function
                break;

            case 2:
                // Deleting node from beginning
                begdelete();   // Call delete function
                break;

            case 3:
                // Exit the program
                exit(0);
                break;

            default:
                // Invalid input
                printf("\nPlease enter valid choice\n");
        }

    } while(choice != 3);  // Loop continues until exit is chosen
}

// Function to insert node at the beginning
void create(int item) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));


    if(ptr == NULL) {
        printf("\nOVERFLOW\n");  // Memory not allocated
    } else {
        ptr->data = item;        // Assign value to the node
        ptr->next = head;        // Point new node to the current head
        head = ptr;              // Update head to the new node
        printf("\nNode inserted\n");
    }
}

// Function to delete a node from the beginning
void begdelete() {
    struct node *ptr;

    if(head == NULL) {
        printf("\nList is empty");  // No node to delete
    } else {
        ptr = head;                 // Store current head
        head = ptr->next;           // Move head to next node
        free(ptr);                  // Free memory of deleted node
        printf("\nNode deleted from the beginning ...");
    }
}

// ■ Output
// 1.Append List
// 2.Delete node
// 3.Exit
// 4.Enter your choice?1

// Enter the item
// 23

// Node inserted

// 1.Append List
// 2.Delete node
// 3.Exit
// 4.Enter your choice?2

// Node deleted from the begining ...