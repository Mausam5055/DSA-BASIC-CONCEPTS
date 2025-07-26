#include <stdio.h>
#include <stdlib.h>

void randominsert(int);
void create(int);

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int item) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\nNode inserted\n");
    }
}

void randominsert(int item) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    int loc, i;

    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("Enter the location: ");
        scanf("%d", &loc);
        ptr->data = item;
        temp = head;

        for (i = 0; i < loc; i++) {
            temp = temp->next;
            if (temp == NULL) {
                printf("\nCan't insert\n");
                return;
            }
        }

        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode inserted\n");
    }
}

int main() {
    int choice, item;

    do {
        printf("\nEnter the item which you want to insert: ");
        scanf("%d", &item);

        if (head == NULL) {
            create(item);
        } else {
            randominsert(item);
        }

        printf("\nPress 0 to insert more: ");
        scanf("%d", &choice);

    } while (choice == 0);

    return 0;
}
