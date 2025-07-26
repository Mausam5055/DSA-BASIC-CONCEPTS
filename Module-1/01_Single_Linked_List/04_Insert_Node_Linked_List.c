#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function declarations
void insertAtBeginning(int item);
void insertAtPosition(int item, int pos);
void displayList();

int main() {
    int choice, item, pos;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at specific position\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                insertAtBeginning(item);
                break;

            case 2:
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                printf("Enter the position (starting from 0): ");
                scanf("%d", &pos);
                insertAtPosition(item, pos);
                break;

            case 3:
                displayList();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to insert a node at the beginning
void insertAtBeginning(int item) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = item;
    newNode->next = head;
    head = newNode;

    printf("Node inserted at beginning.\n");
}

// Function to insert at a given position
void insertAtPosition(int item, int pos) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = item;

    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        printf("Node inserted at position 0.\n");
        return;
    }

    struct node *temp = head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted at position %d.\n", pos);
    }
}

// Function to display the linked list
void displayList() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
