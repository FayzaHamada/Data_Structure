#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int data;
    Node *next;
};

Node *newNode(int x)
{
    Node* temp=malloc(sizeof(Node));
    temp->data = x;
    temp->next=NULL;
   return temp;
}
/// function to find out middle element

Node* middle(Node* start, Node* last)
{ /// if start points to NULL and is empty
    if (start == NULL)
        return NULL;
    Node* slow = start;
    Node* fast = start -> next;
    while (fast != last)
        { /// fast is moved one step ahead
            fast = fast -> next;
    /// if fast is not the last element
    if (fast != last)
        { /// slow pointer is moved one step ahead
            slow = slow -> next;
    /// fast pointer is moved second step ahead
    fast = fast -> next; }
    }
    return slow; }
/// Function for implementing the Binary Search on Singly Linked List
Node* binarySearch(Node *head, int key)
{ Node* start = head;
  Node* last = NULL;
  do
    { /// calling middle function to find middle element
    Node* mid = middle(start, last);
  /// If middle element is empty
  if (mid == NULL)
    return NULL;
  /// If value is present at middle, we return it
  if (mid -> data == key)
    return mid;
  /// If value is more than mid
  else if (mid -> data < key)
    start = mid-> next;
  /// If the value is less than mid.
  else
  last = mid; }
  while (last == NULL || last != start);
  /// value not present, so we return NULL
  return NULL; }

int main()
{Node *head = newNode(1);
head->next =newNode(4);
head->next->next=newNode(7);
head->next->next->next=newNode(8);
head->next->next->next->next=newNode(9);
head->next->next->next->next->next=newNode(10);

int value = 7 ;

if(binarySearch(head,value)==NULL)
    printf("the number [%d] not present \n",value);
else
    printf("\nthe number [%d] present\n",value);

value = 88 ;
if(binarySearch(head,value)==NULL)
    printf("\nthe number [%d] not present \n",value);
else
    printf("\nthe number [%d] present\n",value);


return 0;
}
