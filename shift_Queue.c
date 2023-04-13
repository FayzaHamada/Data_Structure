#include <stdio.h>
#include <stdlib.h>
#define MaxSize 7



typedef struct Queue Queue;
typedef struct Queue
{
    int arr[MaxSize];
    int front, rear;
}Queue;


void Enqueue(Queue *q, int data)
{
    if(q->rear == MaxSize - 1)
    {
       return;
    }

    if(q->front == -  1)
        q->front++;

    q->rear++;
    q->arr[q->rear] = data;
}


void Shift(Queue *q)
{   int index;
    for(index=0;index<q->rear;index++)
{
   q->arr[index]=q->arr[index+1];
}
q->rear--;
}


int Dequeue(Queue *q, int *data)
{
    if(q->front == -1 || q->front > q->rear)
        return 0;

    *data = q->arr[q->front];

    Shift(q);

    return 1;
}

int main()
{   int num;
    Queue que = {.front = -1, .rear = -1};

    Enqueue(&que, 10);
    Enqueue(&que, 20);
    Enqueue(&que, 30);
    Enqueue(&que, 40);
    Enqueue(&que, 50);
    printf("the Queue before any DeQueue\n");

    while(Dequeue(&que, &num))
   {
       printf("%d\n", num);
    }

    printf("the Queue After DeQueue\n");

    Enqueue(&que, 10);
    Enqueue(&que, 20);
    Enqueue(&que, 30);
    Enqueue(&que, 40);
    Enqueue(&que, 50);

    Dequeue(&que, &num);
    Dequeue(&que, &num);

    while(Dequeue(&que, &num))
    {
        printf("%d\n", num);
    }

    return 0;
}
