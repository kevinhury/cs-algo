#include "BinarySearchTree.h"

void insertBST(BTreeNode** bst, int x)
{
    BTreeNode* t = *bst, *parent = NULL;
    while (t != NULL)
    {
        parent = t;
        if (x < t->data)
            t = t->left;
        else
            t = t->right;
    }
    
    BTreeNode *p = malloc(sizeof(BTreeNode));
    p->data = x;
    p->left = p->right = NULL;
    if (parent == NULL)
        *bst = p;
    else if (x < parent->data)
        parent->left = p;
    else if (x > parent->data)
        parent->right = p;
}

void printPreorder(BTreeNode *bst)
{
    if (bst == NULL) return;

    printf("%d", bst->data);
    printPreorder(bst->left);
    printPreorder(bst->right);
}

void printInorder(BTreeNode *bst)
{
    if (bst == NULL) return;

    printInorder(bst->left);
    printf("%d", bst->data);
    printInorder(bst->right);
}

void printPostorder(BTreeNode *bst)
{
    if (bst == NULL) return;

    printPostorder(bst->left);
    printPostorder(bst->right);
    printf("%d", bst->data);
}

void printByLevel(BTreeNode *bst)
{
    // Unimplemented
    exit(1);
}

void clearBTree(BTreeNode **bst)
{
    if (*bst == NULL) return;

    clearBTree(&((*bst)->left));
    clearBTree(&((*bst)->right));
    free(*bst);
    *bst = NULL;
}