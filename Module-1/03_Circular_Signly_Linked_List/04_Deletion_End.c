#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void lastinsert() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
        return;
    }
    printf("\nEnter Data? ");
    scanf("%d", &item);
    ptr->data = item;

    if (head == NULL) {
        head = ptr;
        ptr->next = head;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = ptr;
        ptr->next = head;
    }
    printf("\nNode inserted at the end.\n");
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    temp = head;
    printf("\nCircular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

void last_delete() {
    struct node *ptr, *preptr;

    if (head == NULL) {
        printf("\nUNDERFLOW\n");
    } else if (head->next == head) {
        ptr = head;
        head = NULL;
        free(ptr);
        printf("\nOnly node deleted.\n");
    } else {
        ptr = head;
        while (ptr->next != head) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = head;
        free(ptr);
        printf("\nLast node deleted.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert at End\n2. Delete from End\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: lastinsert(); break;
            case 2: last_delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
