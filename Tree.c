#include <stdio.h>
#include <stdlib.h>

typedef struct Tree Tree;
typedef struct Node Node;

struct Node
{
    int Data;
    Node *Left, *Right;
};

struct Tree
{
    Node *Root;
};

Node* Create(int data)
{
    Node *node = malloc(sizeof(Node));
    node->Data = data;
    node->Left = node->Right = NULL;

    return node;
}

void Add(Tree *tree, int data)
{
    Node *node = Create(data);

    if(tree->Root == NULL)
    {
        tree->Root = node;
    }
    else
    {
        Node *current = tree->Root;
        Node *parent;

        while(current != NULL)
        {
            parent = current;

            if(data > current->Data)
                current = current->Right;
            else
                current = current->Left;
        }

        if(data > parent->Data)
            parent->Right = node;
        else
            parent->Left = node;
    }
}

Node* GetNodeByData(Tree *tree, int data)
{
    Node *current = tree->Root;

    while(current != NULL)
    {
        if(data == current->Data)
            return current;

        if(data > current->Data)
            current = current->Right;
        else
            current = current->Left;
    }

    return NULL;
}

Node* GetParentByNode(Tree *tree, Node *node)
{
    Node *parent = tree->Root;

    while(parent != NULL)
    {
        if(parent->Left == node || parent->Right == node)
            return parent;

        if(node->Data > parent->Data)
            parent = parent->Right;
        else
            parent = parent->Left;
    }

    return NULL;
}


Node* GetMaxRight(Node *node)
{
    while(node->Right != NULL)
        node = node->Right;

    return node;
}

void Remove(Tree *tree, int data)
{
    Node *node = GetNodeByData(tree, data);

    if(node == NULL)
        return;

    if(node == tree->Root)
    {
        if(node->Left == NULL && node->Right == NULL)
        {
            tree->Root = NULL;
        }
        else if(node->Right == NULL)
        {
            tree->Root = tree->Root->Left;
        }
        else if(node->Left == NULL)
        {
            tree->Root = tree->Root->Right;
        }
        else
        {
            Node *newRoot = node->Left;
            Node *maxRight = GetMaxRight(newRoot);

            maxRight->Right = node->Right;
            tree->Root = newRoot;
        }
    }
    else
    {
        Node *parent = GetParentByNode(tree, node);
        Node *newChild;

        if(node->Left == NULL && node->Right == NULL)
        {
            newChild = NULL;
        }
        else if(node->Right == NULL)
        {
            newChild = node->Left;
        }
        else if(node->Left == NULL)
        {
            newChild = node->Right;
        }
        else
        {
            Node *newParent = node->Left;
            Node *maxRight = GetMaxRight(newParent);

            maxRight->Right = node->Right;
            newChild = newParent;
        }

        if(parent->Left == node)
            parent->Left = newChild;
        else
            parent->Right = newChild;
    }

    free(node);
}
int maxDepth(Node* node)
{
    if(node==NULL)
        return 0;
    else
    {   ///compute the depth of each subtree
        int leftDepth = maxDepth(node->Left);
        int rightDepth = maxDepth(node->Right);

        ///use the largest one
        if(leftDepth>rightDepth)
            return (leftDepth+1);
        else
            return (rightDepth+1);
    }
}

///helper function that allocate a new node with the given data and null left and right pointers
Node* newNode(int data)
{
Node* Node = malloc(sizeof(Node));
Node->Data=data;
Node->Left=NULL;
Node->Right=NULL;
return(Node);
}


void Display(Node *node)
{
    if(node == NULL)
        return;

    Display(node->Left);
    printf("%d   ", node->Data);
    Display(node->Right);
}

int main()
{
    Tree tree = {.Root = NULL};

    Add(&tree, 50);
    Add(&tree, 40);
    Add(&tree, 30);
    Add(&tree, 60);
    Add(&tree, 70);
    Add(&tree, 45);
    Add(&tree, 65);
    Add(&tree, 25);

    Display(tree.Root);
    printf("Hight of tree is %d",maxDepth(tree.Root);

    getchar();

    return 0;
}
