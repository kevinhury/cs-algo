#ifndef avltree_h
#define avltree_h

#include <stdio.h>
#include "binarysearchtree.h"

int balance(bst_node *bst);
void avlbalance(bst_node **bst);
void balancedinsert(bst_node **bst, data_t value);

#endif /* avltree_h */
