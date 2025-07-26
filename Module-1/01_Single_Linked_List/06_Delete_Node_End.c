#include <stdio.h>
#include <stdlib.h>

// Function declarations
void create(int);
void end_delete();

// Structure definition for a node
struct node {
    int data;
    struct node *next;
};

// Global pointer to head of the list
struct node *head;

void main() {
    int choice, item;

    // Menu-driven loop
    do {
        // Menu displayed to user
        printf("\n1.Append List\n2.Delete node\n3.Exit\n4.Enter your choice? ");
        scanf("%d", &choice); // Take user's choice

        switch(choice) {
            case 1:
                // Inserting node at beginning
                printf("\nEnter the item\n");
                scanf("%d", &item);
                create(item); // Call create function
                break;

            case 2:
                // Delete node from end
                end_delete(); // Call end_delete function
                break;

            case 3:
                // Exit the program
                exit(0);
                break;

            default:
                // Handle invalid input
                printf("\nPlease enter valid choice\n");
        }

    } while(choice != 3); // Repeat until exit
}

// Function to insert node at beginning
void create(int item) {
   
    struct node *ptr = (struct node *)malloc(sizeof(struct node ));

    if(ptr == NULL) {
        printf("\nOVERFLOW\n"); // Memory allocation failed
    } else {
        ptr->data = item;     // Assign data
        ptr->next = head;     // Point to previous head
        head = ptr;           // Head now points to new node
        printf("\nNode inserted\n");
    }
}

// Function to delete node from the end
void end_delete() {
    struct node *ptr, *ptr1;

    if(head == NULL) {
        // Case: List is empty
        printf("\nList is empty");
    }
    else if(head->next == NULL) {
        // Case: Only one node in the list
        free(head);       // Free the node
        head = NULL;      // Set head to NULL
        printf("\nOnly node of the list deleted ...");
    }
    else {
        // Case: More than one node
        ptr = head;
        // Traverse to the second last node
        while(ptr->next != NULL) {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL; // Set second last node's next to NULL
        free(ptr);         // Free the last node
        printf("\nDeleted node from the last ...");
    }
}


// 1.Append List
// 2.Delete node
// 3.Exit
// 4.Enter your choice? 1

// Enter the item
// 12

// Node inserted

// 1.Append List
// 2.Delete node
// 3.Exit
// 4.Enter your choice? 2

// Only node of the list deleted ...
