#ifndef BinarySearchTree
#define BinarySearchTree

#include <stdlib.h>
#include <stdio.h>

typedef int data_t;

typedef struct bst_node
{
    data_t value;
    struct bst_node *left;
    struct bst_node *right;
} bst_node;


bst_node *createnode(data_t value);

void insert(bst_node **bst, data_t value);

void removenode(bst_node **bst, data_t value);

bst_node *search(bst_node *bst, data_t value);

bst_node *minnode(bst_node *bst);

bst_node *maxnode(bst_node *bst);

void print_preorder(bst_node *bst);

void print_inorder(bst_node *bst);

void print_postorder(bst_node *bst);

void print_by_level(bst_node *bst);

void freetree(bst_node **bst);

#endif
