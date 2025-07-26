#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Head pointer to the list
struct node *head = NULL;

// Function declarations
void insert_beginning();
void insert_end();
void insert_specific();
void delete_beginning();
void delete_end();
void delete_specific();
void search();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n\n=== Doubly Linked List Menu ===\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete Specific Node\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_beginning(); break;
            case 2: insert_end(); break;
            case 3: insert_specific(); break;
            case 4: delete_beginning(); break;
            case 5: delete_end(); break;
            case 6: delete_specific(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Insert at beginning
void insert_beginning() {
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("OVERFLOW\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &item);

    ptr->data = item;
    ptr->prev = NULL;
    ptr->next = head;

    if (head != NULL)
        head->prev = ptr;

    head = ptr;
    printf("Node inserted at beginning.\n");
}

// Insert at end
void insert_end() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("OVERFLOW\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &item);

    ptr->data = item;
    ptr->next = NULL;

    if (head == NULL) {
        ptr->prev = NULL;
        head = ptr;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = ptr;
        ptr->prev = temp;
    }

    printf("Node inserted at end.\n");
}

// Insert at specific location
void insert_specific() {
    struct node *ptr, *temp;
    int item, loc, i;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("OVERFLOW\n");
        return;
    }

    printf("Enter location: ");
    scanf("%d", &loc);
    printf("Enter value to insert: ");
    scanf("%d", &item);
    ptr->data = item;

    temp = head;
    for (i = 1; i < loc; i++) {
        if (temp == NULL) {
            printf("Less than %d elements\n", loc);
            free(ptr);
            return;
        }
        temp = temp->next;
    }

    ptr->next = temp->next;
    ptr->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = ptr;

    temp->next = ptr;

    printf("Node inserted at position %d.\n", loc + 1);
}

// Delete from beginning
void delete_beginning() {
    struct node *ptr;
    if (head == NULL) {
        printf("UNDERFLOW\n");
        return;
    }

    ptr = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(ptr);
    printf("Node deleted from beginning.\n");
}

// Delete from end
void delete_end() {
    struct node *ptr;
    if (head == NULL) {
        printf("UNDERFLOW\n");
        return;
    }

    ptr = head;

    if (ptr->next == NULL) {
        head = NULL;
        free(ptr);
    } else {
        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->prev->next = NULL;
        free(ptr);
    }
    printf("Node deleted from end.\n");
}

// Delete specific node by value
void delete_specific() {
    struct node *ptr, *temp;
    int val;
    if (head == NULL) {
        printf("UNDERFLOW\n");
        return;
    }

    printf("Enter the data to delete: ");
    scanf("%d", &val);
    ptr = head;

    while (ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if (ptr == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    else
        head = ptr->next;

    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;

    free(ptr);
    printf("Node with value %d deleted.\n", val);
}

// Search node
void search() {
    struct node *ptr;
    int item, i = 1, found = 0;

    if (head == NULL) {
        printf("Empty List\n");
        return;
    }

    printf("Enter item to search: ");
    scanf("%d", &item);

    ptr = head;
    while (ptr != NULL) {
        if (ptr->data == item) {
            printf("Item found at position %d\n", i);
            found = 1;
            break;
        }
        i++;
        ptr = ptr->next;
    }

    if (!found)
        printf("Item not found in the list\n");
}

// Display list
void display() {
    struct node *ptr;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List elements:\n");
    ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
