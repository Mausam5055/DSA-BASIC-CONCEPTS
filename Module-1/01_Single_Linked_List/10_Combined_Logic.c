#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at beginning
void insert_beginning(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Node inserted at beginning\n");
}

// Insert at end
void insert_end(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp;

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted at end\n");
}

// Insert at specific position (1-based index)
void insert_at_position(int value, int position) {
    struct node *newNode, *temp;
    int i;

    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        insert_beginning(value);
        return;
    }

    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;

    temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted at position %d\n", position);
    }
}

// Delete at beginning
void delete_beginning() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from beginning\n");
}

// Delete at end
void delete_end() {
    struct node *temp, *prev;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted from end\n");
        return;
    }
    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Node deleted from end\n");
}

// Delete at specific position
void delete_at_position(int position) {
    struct node *temp, *prev;
    int i;
    if (head == NULL || position < 1) {
        printf("Invalid position or list is empty\n");
        return;
    }
    if (position == 1) {
        delete_beginning();
        return;
    }
    temp = head;
    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted from position %d\n", position);
    }
}

// Search node by value
void search(int value) {
    struct node *temp = head;
    int position = 1, found = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, position);
            found = 1;
            break;
        }
        temp = temp->next;
        position++;
    }
    if (!found)
        printf("Value %d not found in the list\n", value);
}

// Display list
void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete at Beginning\n5. Delete at End\n6. Delete at Position\n");
        printf("7. Search\n8. Display\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_beginning(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_end(value);
            break;
        case 3:
            printf("Enter value and position: ");
            scanf("%d %d", &value, &position);
            insert_at_position(value, position);
            break;
        case 4:
            delete_beginning();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &position);
            delete_at_position(position);
            break;
        case 7:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}