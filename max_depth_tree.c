#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int maxDepth(Node* Node)
{
    if(Node==NULL)
        return 0;
    else
    {   ///compute the depth of each subtree
        int leftDepth = maxDepth(Node->left);
        int rightDepth = maxDepth(Node->right);

        ///use the largest one
        if(leftDepth>rightDepth)
            return (leftDepth + 1);
        else
            return (rightDepth + 1);
    }
}

///helper function that allocate a new node with the given data and null left and right pointers
Node* newNode(int data)
{
Node* Node = malloc(sizeof(Node));
Node->data=data;
Node->left=NULL;
Node->right=NULL;
return(Node);
}

int main()
{
    Node* root=newNode(1);
    root->left = newNode(2);
    root->right=newNode(4);
    root->left->left=newNode(1);
    root->left->right=newNode(5);
    root->right->right=newNode(6);
    root->right->left=newNode(3);
    root->right->right->right=newNode(7);

   printf("The Max_Depth of tree is %d",maxDepth(root));

    getchar();
   return 0;

}
