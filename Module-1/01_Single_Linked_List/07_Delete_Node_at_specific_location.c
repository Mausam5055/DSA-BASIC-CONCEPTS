#include <stdio.h>
#include <stdlib.h>

// Function declarations
void create(int);
void delete_specified();

// Node structure
struct node {
    int data;
    struct node *next;
};

// Global head pointer for the linked list
struct node *head;

void main() {
    int choice, item;

    // Menu-driven loop
    do {
        // Display menu
        printf("\n1.Append List\n2.Delete node\n3.Exit\n4.Enter your choice? ");
        scanf("%d", &choice);  // Take user's choice

        switch(choice) {
            case 1:
                // Append node at beginning
                printf("\nEnter the item\n");
                scanf("%d", &item);
                create(item);  // Call insert function
                break;

            case 2:
                // Delete node at specified position
                delete_specified();  // Call delete function
                break;

            case 3:
                // Exit
                exit(0);
                break;

            default:
                // Handle invalid input
                printf("\nPlease enter valid choice\n");
        }

    } while(choice != 3);  // Continue until user chooses to exit
}

// Function to insert a node at the beginning
void create(int item) {
    
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    if(ptr == NULL) {
        printf("\nOVERFLOW\n");  // Memory allocation failed
    } else {
        ptr->data = item;     // Set data
        ptr->next = head;     // Link to existing list
        head = ptr;           // Update head
        printf("\nNode inserted\n");
    }
}

// Function to delete a node at a specified location (0-based index)
void delete_specified() {
    struct node *ptr, *ptr1;
    int loc, i;

    // Take position to delete
    scanf("%d", &loc);

    ptr = head;

    for(i = 0; i < loc; i++) {
        ptr1 = ptr;
        ptr = ptr->next;

        // If list ends before reaching desired index
        if(ptr == NULL) {
            printf("\nThere are less than %d elements in the list..\n", loc);
            return;
        }
    }

    // Link previous node to next node, bypassing current
    ptr1->next = ptr->next;
    free(ptr);  // Free memory of deleted node

    printf("\nDeleted %d node ", loc);
}

//Output:
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
// 4.Enter your choice? 1
// Enter the item
// 23
// Node inserted

// 1.Append List
// 2.Delete node
// 3.Exit
// 4.Enter your choice? 2
// 12
// There are less than 12 elements in the list..

// 1.Append List
// 2.Delete node
// 3.Exit
// 4.Enter your choice? 2
// 1
// Deleted 1 node
