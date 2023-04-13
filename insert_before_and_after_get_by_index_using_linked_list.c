#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

typedef struct node
{
    int data;
    node* next;
    node* prev;
}node;

/// HEAD AND TAIL

node *head = NULL, *tail = NULL;
node *reverse_head = NULL;
node *reverse_tail = NULL;


/// FUNCTIONS DECLARATIONS

node* Create_Node(int data);
void add(int data);
void display ();
void Insert_After(int data,int AfterData);
void InsertBefore(int data,int BeforeData);
int GetByIndex(int index);


int main()
{ add(2);
    add(4);
    add(6);
    add(5);
    Insert_After(3,6);
    InsertBefore(3,6);
    display();
    printf("the index is\n");
  GetByIndex(1) ;
       return 0;
}
/// FUNCTIONS
// 1-Function create
node* Create_Node(int data)
{     node* newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

   return  newnode;

}

/// 2- add
void add(int data)
{
    node* newnode = Create_Node(data);
     if (head == NULL)
        head = tail = newnode;
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode; }
}
///3- display
void display ()
{
    node* current = head;
    while (current != NULL)
    {
        printf("%d\n",current->data);
        current = current->next;
    }
}

///4- search by data
node* getnodebydata(int data)
{
    node* current = head;
    while (current != NULL)
    {
        if (data == current->data)
            return current;
        current = current ->next;
    }
    return NULL;
}


//5_Insert_After_NODE
void Insert_After(int data,int AfterData)
{

    node* insert_A= getnodebydata(AfterData);



    if(insert_A != NULL && insert_A!= tail) //insert at the last
    {
        node* newnode = Create_Node(data);
        insert_A->next->prev = newnode;
        newnode->next        = insert_A->next;
        newnode->prev        = insert_A;
        insert_A->next       = newnode;
    }
    else
        { add(data);}
        return;

}

//6- insert before node

void InsertBefore(int data, int BeforeData)
{ node* insert_B= getnodebydata(BeforeData);

      if(insert_B != NULL && insert_B != tail)
    {
        node* newnode = Create_Node(data);
        insert_B->prev->next = newnode;
        newnode->prev        = insert_B->prev;
        newnode->next       = insert_B;
        insert_B->prev      = newnode;
    }
    else
        { add(data);}
        return;
}

//6_search by index
int GetByIndex(int index)
{
    node *current_node = head;
    int  Position_index = 0;

    for(Position_index ; Position_index < index ; Position_index++)
    {
     if(current_node != NULL)
    {
            current_node = current_node->next;
           printf("%d",current_node->data);
    }
    else
        return -1;
    }
}
