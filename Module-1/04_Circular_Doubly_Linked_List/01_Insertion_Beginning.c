#include <stdio.h>
#include <stdlib.h>

// Define circular doubly linked list node
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insertion_beginning() {
    struct node *ptr, *temp;
    int item;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
        return;
    }

    printf("\nEnter Item value: ");
    scanf("%d", &item);
    ptr->data = item;

    if (head == NULL) {
        head = ptr;
        ptr->next = head;
        ptr->prev = head;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
    printf("\nNode inserted at beginning\n");
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    temp = head;
    printf("\nCircular Doubly Linked List (Forward): ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert at Beginning\n2. Display\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertion_beginning(); break;
            case 2: display(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
