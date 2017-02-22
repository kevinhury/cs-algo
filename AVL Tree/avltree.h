#ifndef avltree_h
#define avltree_h

#include <stdio.h>
#include "binarysearchtree.h"

/**
 * Returns the balance from a given node.
 * In other words it returns the difference between the branches diameters.
 *
 * @param bst The tree's node.
 *
 * @return The difference between the branches diameters.
 */
size_t getbalance(bst_node *bst);

/**
 * Balances the tree so that the two child subtrees of any node differ by at most one.
 * Balancing is done by peforming tree rotations.
 *
 * @param bst The tree's node.
 */
void avlbalance(bst_node **bst);

/**
 * Inserts a new node to the tree while maintaining its balance.
 * 
 * @param bst The tree's node.
 * @param value Value to insert.
 */
void avlinsert(bst_node **bst, data_t value);

#endif /* avltree_h */
