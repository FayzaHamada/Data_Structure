#include <stdio.h>
#include <stdlib.h>
///stack with linked list
typedef struct node node;
typedef struct node{
    int DATA;
    node* link;

}node;
node *top=NULL;

void push(int data){
    node *newNode=newNode=malloc(sizeof(node));
    if(newNode==NULL) {printf("Stack overflow");exit(1);}
    newNode->DATA=data;
    newNode->link=NULL;
    newNode->link=top;
    top=newNode;
}
void display(){

    node* temp=top;
    if(top==NULL)
        printf("stack is empty");
    else{
        while(temp!=NULL)
        {
            printf("%d\n",temp->DATA);
            temp=temp->link;
        }
    }
}
void pop()
{   node *temp;
   if(top == NULL){
      printf("\nStack is Empty!!!\n"); exit(1);}
   else{
      printf("deleted element: %d\n", top->DATA);
      temp = top;
      top=top->link;
      free(temp);
   }
}
int main()
{
    push(3);
    push(5);
    push(7);
    display();
    puts("");
    pop();
    puts("");
    printf("After the pop, the new linked list\n");
    display();
    return 0;
}
