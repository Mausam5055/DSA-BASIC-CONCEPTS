#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insertion_last() {
    struct node *ptr, *temp;
    int item;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &item);
    ptr->data = item;

    if (head == NULL) {
        head = ptr;
        ptr->next = head;
        ptr->prev = head;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = head;
        head->prev = ptr;
    }

    printf("\nNode inserted at the end.\n");
}

void deletion_beginning() {
    struct node *temp;

    if (head == NULL) {
        printf("\nUNDERFLOW\n");
    } else if (head->next == head) {
        temp = head;
        head = NULL;
        free(temp);
        printf("\nOnly node deleted.\n");
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = head->next;
        head->next->prev = temp;

        struct node *toDelete = head;
        head = head->next;
        free(toDelete);

        printf("\nFirst node deleted.\n");
    }
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    temp = head;
    printf("\nCircular Doubly Linked List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert at End\n2. Delete from Beginning\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertion_last(); break;
            case 2: deletion_beginning(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
