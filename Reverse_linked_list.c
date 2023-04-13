#include <stdio.h>

#include <stdlib.h>

//a node of the doubly linked list

 typedef struct Node {

    int data;

    struct  Node* next;

    struct Node* prev;

};

 

/* Function to reverse a Doubly Linked List */

void reverse(struct Node** head_ref)

{

    struct Node* temp = NULL;

    struct Node* current = *head_ref;

 

    /* swap next and prev for all nodes of

      doubly linked list */

    while (current != NULL) {

        temp = current->prev;

        current->prev = current->next;

        current->next = temp;

        current = current->prev;

    }

 

    /* Before changing head, check for the cases like empty

       list and list with only one node */

    if (temp != NULL)

        *head_ref = temp->prev;

}

 

/* UTILITY FUNCTIONS */

/* Function to insert a node at the beginning of the Doubly

 * Linked List */

void push(struct Node** head_ref, int new_data)

{

    /* allocate node */

    struct Node* new_node

        = (struct Node*)malloc(sizeof(struct Node));

 

    /* put in the data  */

    new_node->data = new_data;

 

    /* since we are adding at the beginning,

      prev is always NULL */

    new_node->prev = NULL;
