
#ifndef BinarySearchTree
#define BinarySearchTree

typedef data_type int;

typedef struct BTreeNode
{
    data_type data;
    struct BTreeNode *left;
    struct BTreeNode *right;
} BTreeNode;


void insertBST(BTreeNode **bst, int x);

void printPreorder(BTreeNode *bst);

void printInorder(BTreeNode *bst);

void printPostorder(BTreeNode *bst);

void printByLevel(BTreeNode *bst);

void clearBTree(BTreeNode **bst);

#endif