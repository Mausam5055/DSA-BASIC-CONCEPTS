#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Head pointer (global)
struct node *head = NULL;

// Function to insert node at beginning
void insertion_beginning() {
    struct node *ptr;
    int item;

    // Allocate memory for new node
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("\nOVERFLOW");
        return;
    }

    printf("\nEnter Item value: ");
    scanf("%d", &item);

    ptr->data = item;

    if (head == NULL) {
        // List is empty
        ptr->next = NULL;
        ptr->prev = NULL;
        head = ptr;
    } else {
        // Insert at beginning
        ptr->prev = NULL;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }

    printf("\nNode inserted\n");
}

// Function to display list (for testing)
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    printf("\nDoubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function with menu
int main() {
    int choice;

    do {
        printf("\n1. Insert at beginning");
        printf("\n2. Display list");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertion_beginning();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting...");
                break;
            default:
                printf("\nInvalid choice!");
        }

    } while (choice != 3);

    return 0;
}
