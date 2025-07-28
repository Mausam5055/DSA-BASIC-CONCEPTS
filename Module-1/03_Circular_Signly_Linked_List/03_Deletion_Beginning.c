#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Declare the head pointer
struct node *head = NULL;

void begin_delete() {
    struct node *ptr, *temp;

    if (head == NULL) {
        printf("\nUNDERFLOW\n");
    } else if (head->next == head) {
        ptr = head;
        head = NULL;
        free(ptr);
        printf("\nOnly node deleted.\n");
    } else {
        ptr = head;
        temp = head;
        // Traverse to the last node
        while (ptr->next != head) {
            ptr = ptr->next;
        }
        // Point last node to second node
        ptr->next = head->next;
        head = head->next;
        free(temp);
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
    printf("\nCircular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

void lastinsert() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("\nEnter Data? ");
        scanf("%d", &item);
        ptr->data = item;

        if (head == NULL) {
            head = ptr;
            ptr->next = head;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
        }
        printf("\nNode inserted at the end.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert at End\n2. Delete from Beginning\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                lastinsert();
                break;
            case 2:
                begin_delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
