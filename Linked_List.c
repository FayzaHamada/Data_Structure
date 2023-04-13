#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int Data;
    Node *Next, *Prev;
};


Node *head = NULL, *tail = NULL;

Node* Create(int data)
{
    Node *newNode = malloc(sizeof(Node));

    newNode->Data = data;
    newNode->Prev = newNode->Next = NULL;

    return newNode;
}

void Add(int data)
{
    Node *newNode = Create(data);

    if(head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->Next = newNode;
        newNode->Prev = tail;
        tail = newNode;
    }
}

void Display()
{
    Node *current = head;

    while(current != NULL)
    {
        printf("%d \n", current->Data);
        current = current->Next;
    }
}

Node* GetNodeByData(int data)
{
    Node *current = head;

    while(current != NULL)
    {
        if(data == current->Data)
        {
            return current;
        }

        current = current->Next;
    }

    return NULL;
}

void InsertAfter(int data,int afterData)
{
    Node *newNode = Create(data);
    Node *previous_node = GetNodeByData(afterData);

    if(previous_node == head)
    {
        if(previous_node == tail)
        {
        tail->Next = newNode;
        newNode->Prev = tail;
        tail = newNode;
        }
       /* else
        {
            previous_node->Next->Prev =newNode;
            newNode->Next= previous_node->Next;
            newNode->Prev=previous_node;
            previous_node->Next->Prev=newNode;
        }*/
    }
    else if(previous_node == tail)
    {
        previous_node->Next=newNode;

        newNode->Next = NULL;
        tail=newNode;
    }
   else
    {
       // Node *A = deletedNode->Prev;
       // Node *B = deletedNode->Next;

       // A->Next = B;
       // B->Prev = A;
        previous_node->Next->Prev = newNode;
        newNode->Next= previous_node->Next;
        newNode->Prev=previous_node;
        previous_node->Next=newNode;
    }
}
void Insertbefor(int data, int beforData)
{ Node* next_node= GetNodeByData(beforData);

      if(next_node != NULL && next_node != tail)
    {
        Node* newNode = Create(data);
        next_node->Prev->Next = newNode;
        newNode->Prev = next_node->Prev;
        newNode->Next = next_node;
        next_node->Prev = newNode;
    }
    else
        { Add(data);}
        return;
}
//6_search by index
/*int GetByIndex(int index)
{
    Node *current_node = head;
    int  Position_index = 0;

    for(Position_index ; Position_index < index ; Position_index++)
    {
     if(current_node != NULL)
    {
            current_node = current_node->Next;
           printf("%d",current_node->Data);
    }
    else
        return -1;
    }
}*/ //This code is wrong

int GetByIndex(int index)
{
 Node *current_node=head;
 int count=0;
 while(current_node!=NULL)
 { if (index == count)
    return current_node->Data;

 else
    {   count++;
        current_node = current_node->Next;
    }
 }
 return 0;}







void Remove(int data)
{
    Node *deletedNode = GetNodeByData(data);

    if(deletedNode == NULL)
        return;

    if(deletedNode == head)
    {
        if(deletedNode == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->Next;
            head->Prev = NULL;
        }
    }
    else if(deletedNode == tail)
    {
        tail = tail->Prev;
        tail->Next = NULL;
    }
    else
    {
        Node *A = deletedNode->Prev;
        Node *B = deletedNode->Next;

        A->Next = B;
        B->Prev = A;
        /*deletedNode->Prev->Next = deletedNode->Next;
        deletedNode->Next->Prev = deletedNode->Prev;*/
    }

    free(deletedNode);
}

void InsertAfter(int data, int afterData);
void Insertbefor(int data, int beforData);
void GetCount();
int GetByIndex(int index);


void Test(int **p)
{
    int y = 9;

   printf("%d",*p = malloc(40));
}

int main()
{ int dataIndex;
    Add(3);
    Add(5);
    Add(7);
    Add(9);

    Display();
    printf("insert_after\n");
    InsertAfter(8,7);
    InsertAfter(7,3);
    Display();
    printf("insert_befor\n");
    Insertbefor(4,5);
    Insertbefor(4,7);
    Display();
    printf("your index data is\n");
    dataIndex = GetByIndex(5);
    printf("Data at Index %d in LinkedList L1 = %d\n",2, dataIndex);
    GetByIndex(1);

    //Remove(5);

   // InsertAfter(6, 5);

  //  int x =3;
    //int *ptr = &x;

    //Test(&ptr);

    return 0;
}
