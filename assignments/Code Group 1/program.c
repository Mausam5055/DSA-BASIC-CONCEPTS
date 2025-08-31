#include <stdio.h>
 #include <stdlib.h>
 void createList();
 void insertAtBeginning();
 void insertAtEnd();

void insertAtPosition();
 void deleteFromBeginning();
 void deleteFromEnd();
 void deleteFromPosition();
 void traverse();
 // Define the structure for a node in the linked list
 struct Node {
    int data;
    struct Node *next;
 };
 // Global pointer to the first node of the list
 struct Node *head = NULL;
 int main() {
    int choice;
    // The main menu loop
    while (1) {
        printf("\n\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Create List\n");
        printf("2. Display List (Traversal)\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Insert at a specific position\n");
        printf("6. Delete from the beginning\n");
        printf("7. Delete from the end\n");
        printf("8. Delete from a specific position\n");
        printf("9. Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createList();

                break;
            case 2:
                traverse();
                break;
            case 3:
                insertAtBeginning();
                break;
            case 4:
                insertAtEnd();
                break;
            case 5:
                insertAtPosition();
                break;
            case 6:
                deleteFromBeginning();
                break;
            case 7:
                deleteFromEnd();
                break;
            case 8:
                deleteFromPosition();
                break;
            case 9:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 9.\n");
        }
    }
    return 0;
 }
 void createList() {
    if (head != NULL) {
        printf("List already exists. Creating a new one will erase the old one.\n");
        // Free the old list before creating a new one (optional, but good practice)
        struct Node *temp = head, *nextNode;
        while (temp != NULL) {
            nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
        head = NULL;
    }
    int n, data, i;
    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Number of nodes should be greater than 0.\n");
        return;
    }
    struct Node *newNode, *temp;
    // Create the head node
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL) {
        printf("Unable to allocate memory.\n");
        return;
    }
    head->data = data;
    head->next = NULL;
    temp = head;
    // Create remaining nodes

    for (i = 2; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Unable to allocate memory.\n");
            return;
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode; // Link previous node with the new node
        temp = temp->next;    // Move temp to the current node
    }
    printf("Linked list created successfully.\n");
 }
 void insertAtBeginning() {
    struct Node *newNode;
    int data;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Unable to allocate memory.\n");
        return;
    }
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = head;  // Point new node's next to the current head
    head = newNode;       // Make the new node the new head
    printf("Data inserted at the beginning.\n");
 }

void insertAtEnd() {
    struct Node *newNode, *temp;
    int data;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Unable to allocate memory.\n");
        return;
    }
    printf("Enter data to insert at the end: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL; // The new last node's next should be NULL
    if (head == NULL) {
        // If the list is empty, the new node becomes the head
        head = newNode;
    } else {
        // Traverse to the end of the list
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode; // Link the last node to the new node
    }
    printf("Data inserted at the end.\n");
 }
 void insertAtPosition() {
    struct Node *newNode, *temp;
    int pos, data, i;

    printf("Enter the position to insert at: ");
    scanf("%d", &pos);
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        // Position 1 is the beginning
        insertAtBeginning();
    } else {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Unable to allocate memory.\n");
            return;
        }
        printf("Enter data for the new node: ");
        scanf("%d", &data);
        newNode->data = data;
        temp = head;
        // Traverse to the node just before the insertion position
        for (i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of range. Cannot insert.\n");
            free(newNode); // Free the allocated memory if insertion fails
        } else {
            newNode->next = temp->next; // New node points to the next node
            temp->next = newNode;       // Previous node points to the new node

            printf("Data inserted at position %d.\n", pos);
        }
    }
 }
 void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next; // Move head to the second node
    printf("Deleted data: %d\n", temp->data);
    free(temp); // Free the memory of the original first node
 }
 void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    if (temp->next == NULL) {
        // Only one node in the list
        printf("Deleted data: %d\n", temp->data);
        free(temp);
        head = NULL;
    } else {
        // Traverse to the end, keeping track of the previous node
        while (temp->next != NULL) {

            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL; // Unlink the last node
        printf("Deleted data: %d\n", temp->data);
        free(temp); // Free the last node
    }
 }
 void deleteFromPosition() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    int pos, i;
    struct Node *temp = head, *prev = NULL;
    printf("Enter the position to delete from: ");
    scanf("%d", &pos);
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        // Position 1 is the beginning
        deleteFromBeginning();
    } else {
        // Traverse to the node to be deleted
        for (i = 1; i < pos && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Position out of range. Cannot delete.\n");
        } else {
            prev->next = temp->next; // Bypass the node to be deleted
            printf("Deleted data: %d from position %d.\n", temp->data, pos);
            free(temp); // Free the memory
        }
    }
 }
 void traverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Linked List: HEAD -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
 }
