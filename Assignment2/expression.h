#include <stdio.h>
#include <stdlib.h>

typedef struct ExpressionTreeNode{
    char key;
    Node *left;
    Node *right;
}Node;

typedef struct ExpressionTree{
    Node *root;
    
}

Node *newTreeNode (char key)
{
    Node *newTreeNode = (Node*)malloc(sizeof(Node));
    newTreeNode->key = key;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;
    return newTreeNode;
}

