
#ifndef BinarySearchTree
#define BinarySearchTree

#include <stdlib.h>
#include <stdio.h>

typedef int data_type;

typedef struct BTreeNode
{
    data_type data;
    struct BTreeNode *left;
    struct BTreeNode *right;
} BTreeNode;


void insert(BTreeNode **bst, data_type x);

void printPreorder(BTreeNode *bst);

void printInorder(BTreeNode *bst);

void printPostorder(BTreeNode *bst);

void printByLevel(BTreeNode *bst);

void clearBTree(BTreeNode **bst);

#endif
