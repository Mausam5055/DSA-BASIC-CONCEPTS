#include <stdio.h>
#include <stdlib.h>

// Function declarations
void create(int);
void traverse();

// Node structure
struct node {
    int data;
    struct node *next;
};

// Global pointer to the head of the list
struct node *head;

void main() {
    int choice, item;

    // Menu-driven loop
    do {
        // Display menu
        printf("\n1.Append List\n2.Traverse\n3.Exit\n4.Enter your choice? ");
        scanf("%d", &choice);  // Read user choice

        switch(choice) {
            case 1:
                // Add node
                printf("\nEnter the item\n");
                scanf("%d", &item);
                create(item);  // Call create function
                break;

            case 2:
                // Traverse list
                traverse();  // Call traverse function
                break;

            case 3:
                // Exit program
                exit(0);
                break;

            default:
                // Invalid input
                printf("\nPlease enter valid choice\n");
        }

    } while(choice != 3);  // Loop until user chooses to exit
}

// Function to insert a node at the beginning
void create(int item) {
    
    struct node *ptr = (struct node *)malloc(sizeof(struct node ));

    if(ptr == NULL) {
        printf("\nOVERFLOW\n");  // Memory allocation failed
    } else {
        ptr->data = item;       // Set node data
        ptr->next = head;       // Link node to current head
        head = ptr;             // Move head to new node
        printf("\nNode inserted\n");
    }
}

// Function to print the list
void traverse() {
    struct node *ptr;
    ptr = head;

    if(ptr == NULL) {
        // Empty list
        printf("Empty list..");
    } else {
        // Print nodes
        printf("printing values . . . . .\n");
        while (ptr != NULL) {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}



//OUTPUT:
// 1.Append List
// 2.Traverse
// 3.Exit
// 4.Enter your choice? 1
// Enter the item
// 23
// Node inserted

// 1.Append List
// 2.Traverse
// 3.Exit
// 4.Enter your choice? 1
// Enter the item
// 233
// Node inserted

// 1.Append List
// 2.Traverse
// 3.Exit
// 4.Enter your choice? 2
// printing values . . . . .
// 233
// 23
