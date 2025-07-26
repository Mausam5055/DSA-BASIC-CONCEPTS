#include <stdio.h>
#include <stdlib.h>

// Function declarations
void create(int);
void search();

// Node structure
struct node {
    int data;
    struct node *next;
};

// Global head pointer for linked list
struct node *head;

void main() {
    int choice, item;

    // Menu-driven loop
    do {
        // Display menu
        printf("\n1.Create\n2.Search\n3.Exit\n4.Enter your choice? ");
        scanf("%d", &choice);  // Read user's choice

        switch(choice) {
            case 1:
                // Insert a new node
                printf("\nEnter the item\n");
                scanf("%d", &item);
                create(item);
                break;

            case 2:
                // Search for a node
                search(); // ⚠️ Missing break statement (will also execute case 3)
                break;

            case 3:
                // Exit the program
                exit(0);

            default:
                printf("\nPlease enter valid choice\n");
        }
    } while(choice != 3);
}

// Function to insert node at beginning
void create(int item) {

    struct node *ptr = (struct node *)malloc(sizeof(struct node )); 

    if(ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\nNode inserted\n");
    }
}

// Function to search for a node by value
void search() {
    struct node *ptr;
    int item, i = 0, flag = 0; // flag initialized to 0 (not found)
    ptr = head;

    if(ptr == NULL) {
        printf("\nEmpty List\n");
    } else {
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item);

        while(ptr != NULL) {
            if(ptr->data == item) {
                printf("Item found at location %d\n", i + 1);
                flag = 1; // Item found
                break;    // Stop after first match
            }
            i++;
            ptr = ptr->next;
        }

        if(flag == 0) {
            printf("Item not found\n");
        }
    }
}


//output:
// 1.Create
// 2.Search
// 3.Exit
// 4.Enter your choice? 1
// Enter the item
// 23
// Node inserted

// 1.Create
// 2.Search
// 3.Exit
// 4.Enter your choice? 2
// Enter item which you want to search?
// 34
// Item not found

// 1.Create
// 2.Search
// 3.Exit
// 4.Enter your choice? 1
// Enter the item
// 34
// Node inserted

// 1.Create
// 2.Search
// 3.Exit
// 4.Enter your choice? 2
// Enter item which you want to search?
// 34
// Item found at location 1
