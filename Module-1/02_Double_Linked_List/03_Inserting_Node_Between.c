#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insertion_specified() {
    struct node *ptr, *temp;
    int item, loc, i;

    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL) {
        printf("\nOVERFLOW\n");
        return;
    }

    printf("Enter the location after which to insert: ");
    scanf("%d", &loc);

    if(head == NULL) {
        printf("\nList is empty, can't insert at location %d\n", loc);
        free(ptr);
        return;
    }

    temp = head;
    for(i = 1; i < loc; i++) {
        temp = temp->next;
        if(temp == NULL) {
            printf("\nThere are less than %d elements\n", loc);
            free(ptr);
            return;
        }
    }

    printf("Enter value to insert: ");
    scanf("%d", &item);
    ptr->data = item;

    ptr->next = temp->next;
    ptr->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = ptr;

    temp->next = ptr;

    printf("\nNode inserted at position %d\n", loc + 1);
}
