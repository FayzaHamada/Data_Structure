#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int Data;
    Node *Next;
};
//function to swap the nodes
Node* swap(Node *ptr1 , Node *ptr2)
{
    Node* tmp = ptr2->Next;
    ptr2->Next = ptr1;
    ptr1->Next = tmp;
    return ptr2;
}
//Function to sort the list
int bubbleSort(Node** head ,int count )
{
    Node** h;
    int i,j ,swapped;
    for (i=0;i<=count;i++)
    { h=head ;
      swapped=0;
      for(j=0;j<count-i-1;i++)
      {Node* p1 =*h;
       Node* p2 =p1->Next;
       if (p1->Data > p2->Data)
       {
           *h = swap(p1,p2); ///update the link after swapping
           swapped =1 ;
       }
       h= &(*h)->Next;
      }


     if (swapped==0)
        break;  ///break if the loop ended without any swap.....
               ///this is mean that the data is sorted from the beginning
        }
    }



    ///Function to display the list
void display(Node* n )
{
    while (n!=NULL)
    {
        printf("%d -> ", n->Data);
        n=n->Next;
    }
    printf("\n");
}

///function to insert a Node at the beginning of the linkedList
void insertAtTheBegin(Node** start_ref, int data)   ///we need to use pointer to pointer to keep the difference
{
    Node* ptr1 =malloc(sizeof(Node));
    ptr1->Data=data;
    ptr1->Next =*start_ref;
    *start_ref = ptr1;

}


int main()
{
int arr[] = {78,20,10,32,1,5};
int list_size,i;

Node* start = NULL; ///let's start with empty linked list

list_size = sizeof(arr) / sizeof(arr[0]);  ///let's start with empty linked list

///create linkedList from the array arr[]

for(i=0;i<list_size;i++)
    insertAtTheBegin(&start,arr[i]);

///print the list before sorting
printf("\nLinkedList before sorting\n\n");
display(start);

///sort the linkedList
bubbleSort(&start , list_size);

///print the list after sorting
printf("\nLinkedList after sorting\n\n ");
display(start);

    return 0;
}
