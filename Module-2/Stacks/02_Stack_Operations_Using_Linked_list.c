#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

struct node {
    int val;
    struct node *next;
};

struct node *head = NULL;

void main() {
    int choice = 0;

    printf("\n********* Stack operations using linked list *********\n");
    printf("----------------------------------------------\n");

    while (choice != 4) {
        printf("\n\nChoose one from the below options...\n");
        printf("1. Push\n2. Pop\n3. Show\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting....\n");
                break;

            default:
                printf("Please enter a valid choice.\n");
        }
    }
}

void push() {
    int val;
    struct node *ptr = (struct node*) malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("Not able to push the element (Memory allocation failed).\n");
    } else {
        printf("Enter the value: ");
        scanf("%d", &val);

        ptr->val = val;
        ptr->next = head;
        head = ptr;

        printf("Item pushed.\n");
    }
}

void pop() {
    struct node *ptr;

    if (head == NULL) {
        printf("Underflow\n");
    } else {
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item popped.\n");
    }
}

void display() {
    struct node *ptr = head;

    if (ptr == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Printing Stack elements:\n");
        while (ptr != NULL) {
            printf("%d\n", ptr->val);
            ptr = ptr->next;
        }
    }
}
