#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Function to create and add a node at the end (for testing)
void insert_end(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to search node at a given position (1-based index)
void search_at_position(int position) {
    struct node *temp = head;
    int i = 1;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL && i < position) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position %d does not exist in the list.\n", position);
    } else {
        printf("Node at position %d has data: %d\n", position, temp->data);
    }
}

// Test the function
int main() {
    // Inserting some test data
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);

    int pos;
    printf("Enter the position to search: ");
    scanf("%d", &pos);

    search_at_position(pos);

    return 0;
}
