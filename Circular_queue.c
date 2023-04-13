#include <stdio.h>
#include <Windows.h>
#define MAX_SIZE 5

typedef struct Queue
{
    int arr[MAX_SIZE];
    int front, rear;
}Queue;

void enqueue(Queue *q, int data)
{
if (q->front == -1 && q->rear == -1)
{
q->front = q->rear = 0;
}
else if ((q->front == 0 && q->rear==MAX_SIZE-1)||(q->rear + 1) % MAX_SIZE == q->front)
{
//printf("queue is full\n");
return;
}
else
q->rear = (q->rear + 1) % MAX_SIZE;
q->arr[q->rear] = data;
}
void dequeue(Queue *q, int *data)
{
if (q->front == -1 && q->rear== -1)
{
//printf("queue is empty \n");
return;
}
else if (q->front == q->rear)
{
q->front = q->rear = -1;
}
else
q->front = (q->front + 1) % MAX_SIZE;
}
/*int Peek()
{
if (a[front] == -1)
return -1;
return a[front];
}*/
void display(Queue *q)
{
int count = ((q->rear + MAX_SIZE - q->front) % MAX_SIZE)+1;
int i;
for (i = 0; i < count; i++)
{
printf("%d ", q->arr[(q->front+i)%MAX_SIZE]);
}
printf("\n");
}
int main(void)
{
    int num=0;
    Queue que = {.front = -1, .rear = -1};

enqueue(&que, 10);
printf("\nFirst insertion in circular Queue\n");
display(&que);

printf("\n Second insertion in circular Queue\n");
enqueue(&que, 7);
display(&que);

printf("\n Third insertion in circular Queue\n");
enqueue(&que, -3);
display(&que);

printf("\n Fourth insertion in circular Queue\n");
enqueue(&que, 6);
display(&que);

printf("\n Circular Queue after first deletion\n");
dequeue(&que, &num);
display(&que);

printf("\n Circular Queue after 2nd deletion\n");
dequeue(&que, &num);
display(&que);

printf("\n Insertion in circular Queue\n");
enqueue(&que, 7);
display(&que);
enqueue(&que, 9);
enqueue(&que, 5);

printf("\ncircular Queue IS full naw\n");
display(&que);
printf("\n****----------------------------------------------------------------****\n");

enqueue(&que, 8);
dequeue(&que, &num);
printf("\ncircular Queue has one free place naw\n");

display(&que);
printf("\nwe can insert new element now \n");
enqueue(&que, 2);
display(&que);

return 0;
}
