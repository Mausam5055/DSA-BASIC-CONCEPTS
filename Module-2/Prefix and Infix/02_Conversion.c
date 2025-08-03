#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct node {
    int data;
    struct node *next;
};

// Global front and rear pointers for the queue
struct node *front = NULL;
struct node *rear = NULL;

// Function prototypes
void insert();
void delete_element();
void display();


// Main function with a menu-driven interface
int main() {
    int choice = 0; // Initialize choice to enter the loop

    while (choice != 4) {
        printf("\n**Main Menu\n");
        printf("=================================================================\n");
        printf("1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete_element();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program.\n");
                exit(0);
                break;
            default:
                printf("\nPlease enter a valid choice (1-4).\n");
        }
    }
    return 0;
}

// Function to insert a new node at the rear of the queue
void insert() {
    struct node *ptr;
    int item;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW: Cannot allocate memory.\n");
        return;
    }

    printf("\nEnter value to insert: ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = NULL;

    if (front == NULL) { // If the queue is empty
        front = ptr;
        rear = ptr;
    } else { // If the queue is not empty
        rear->next = ptr;
        rear = ptr;
    }
    printf("\nNode inserted successfully.\n");
}

// Function to delete a node from the front of the queue
void delete_element() {
    struct node *ptr;
    if (front == NULL) {
        printf("\nUNDERFLOW: Queue is empty.\n");
        return;
    } else {
        ptr = front;
        int deleted_value = ptr->data;
        front = front->next;

        // If the queue becomes empty after deletion, update rear as well
        if (front == NULL) {
            rear = NULL;
        }

        free(ptr);
        printf("\nValue deleted: %d\n", deleted_value);
    }
}

// Function to display all the elements in the queue
void display() {
    struct node *ptr;
    ptr = front;
    if (ptr == NULL) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nPrinting queue elements ....\n");
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}