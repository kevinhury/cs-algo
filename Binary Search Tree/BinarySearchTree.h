#ifndef BinarySearchTree
#define BinarySearchTree

#include <stdlib.h>
#include <stdio.h>

typedef int data_type;

typedef struct bst_node
{
    data_type data;
    struct bst_node *left;
    struct bst_node *right;
} bst_node;


void insert(bst_node **bst, data_type x);

void print_preorder(bst_node *bst);

void print_inorder(bst_node *bst);

void print_postorder(bst_node *bst);

void print_by_level(bst_node *bst);

void clear_tree(bst_node **bst);

#endif
