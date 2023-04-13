#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

typedef struct Stack
{
    int arr[MaxSize];
    int top;
}Stack;

int Push(Stack *s, int data)
{
    if(s->top == MaxSize - 1)
    {
        return 0;
    }

    s->top++;

    s->arr[s->top] = data;
    return 1;
}

int Pop(Stack *s, int *data)
{
    if(s->top == -1)
    {
        return 0;
    }

    *data = s->arr[s->top];
    s->top--;

    return 1;
}


int main()
{
    /*Stack stk = {.top = -1};

    Push(&stk, 10);
    Push(&stk, 20);
    Push(&stk, 30);

    int num;
    int success = Pop(&stk, &num);
    if(success)
    {
        printf("%d\n", num);
    }
    else
    {
        printf("Stack is empty");
    }

    while(Pop(&stk, &num))
    {
        printf("%d\n", num);
    }*/

    Queue que = {.front = -1, .rear = -1};

    Enqueue(&que, 10);
    Enqueue(&que, 20);
    Enqueue(&que, 30);

    int num;
    while(Dequeue(&que, &num))
    {
        printf("%d\n", num);
    }

    return 0;
}
