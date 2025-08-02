#include <stdio.h>
#include <stdlib.h> // For exit()

// Define the maximum size of the queue
#define maxsize 5

// Function prototypes
void insert();
void delete_element(); // Renamed to avoid conflict with 'delete' keyword in C++
void display();

// Global variables for the queue
int front = -1, rear = -1;
int queue[maxsize];

// Main function with menu-driven interface
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
                exit(0);
                break;
            default:
                printf("\nEnter valid choice??\n");
        }
    }
    return 0;
}

// Function to insert an element into the queue
void insert() {
    int item;
    printf("\nEnter the element: ");
    scanf("%d", &item);

    if (rear == maxsize - 1) {
        printf("\nOVERFLOW\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = rear + 1;
    }
    queue[rear] = item;
    printf("\nValue inserted ");
}

// Function to delete an element from the queue
void delete_element() {
    int item;
    if (front == -1 || front > rear) {
        printf("\nUNDERFLOW\n");
        return;
    } else {
        item = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = front + 1;
        }
        printf("\nValue deleted: %d", item);
    }
}

// Function to display the elements of the queue
void display() {
    int i;
    if (rear == -1) {
        printf("\nEmpty queue\n");
    } else {
        printf("\nPrinting values .....\n");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}