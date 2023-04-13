#include <stdio.h>
#include <stdlib.h>
/// Queue with linked list
typedef struct node node;
typedef struct node{
    int DATA;
    node* next;
}node;

node *front=NULL;
node *rear=NULL;

void Enqueue( int data){
    node *newNode=newNode=malloc(sizeof(node));
    newNode->DATA=data;
    newNode->next=NULL;
    if(front==NULL&&rear==NULL) front=rear=newNode;
        rear->next=newNode;
        rear=newNode;


}void Dequeue(){
    node* temp= front;
    if(front==NULL)return;
    if(front==rear) front=rear=NULL;
    else front=front->next;

    free(temp);

}
void display(){
    node* temp=front;
    if(front==NULL&&rear==NULL)exit(1);
    while(temp!=NULL){
        printf("%d\n",temp->DATA);
        temp=temp->next;
    }

}

int main()
{
    Enqueue(3);
    Enqueue(5);
    Enqueue(7);
    display();
    puts("");
    printf("After the Dequeue, the new linked list\n");
    Dequeue();
    display();
    return 0;
}
