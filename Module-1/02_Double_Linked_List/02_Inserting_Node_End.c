#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Declare the head pointer globally
struct node *head = NULL;

// Function to insert node at the end
void insertion_last() {
    struct node *ptr, *temp;
    int item;

    ptr = (struct node *) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &item);

    ptr->data = item;
    ptr->next = NULL;

    if (head == NULL) {
        // First node in the list
        ptr->prev = NULL;
        head = ptr;
    } else {
        // Traverse to the last node
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }

    printf("\nNode inserted at the end\n");
}

// Function to display the list
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
        printf("\n1. Insert at last");
        printf("\n2. Display list");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertion_last();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("\nInvalid choice!");
        }

    } while (choice != 3);

    return 0;
}
