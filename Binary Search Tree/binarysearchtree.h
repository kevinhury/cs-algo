#ifndef BinarySearchTree
#define BinarySearchTree

#include <stdlib.h>
#include <stdio.h>

typedef void* data_t;

typedef struct bst_node
{
    data_t value;
    struct bst_node *left;
    struct bst_node *right;
} bst_node;


/**
 * Creates a new (dynamic) binary search tree node with a given value.
 * The node is dynamically allocated so it needs to be free.
 *
 * @param value The new leaf's data.
 *
 * @return Pointer to the newly created leaf.
 */
bst_node *createnode(data_t value);

/**
 * Inserts a new node to the binary search tree.
 *
 * @param bst The root of the binary search tree.
 * @param value The new leaf's data.
 */
void insert(bst_node **bst, data_t value);

/**
 * Removes the node's with the given value and reorders the tree.
 * The node gets free after the operation is finished.
 *
 * @param bst The root of the binary search tree.
 * @param value The value to remove from the tree.
 */
void removenode(bst_node **bst, data_t value);

/**
 * Searchs a node in a given tree and returns it.
 *
 * @param bst The root of the binary search tree.
 * @param value The value to look.
 *
 * @return The node in binary search tree with the given value. Returns NULL if not found.
 */
bst_node *search(bst_node *bst, data_t value);

/**
 * Returns the node with the minimum value in the tree.
 * In other words it returns the left-most located node in the binary search tree.
 *
 * @param bst The root of the binary search tree.
 *
 * @return The minimum node in the tree.
 */
bst_node *minnode(bst_node *bst);

/**
 * Returns the node with the maximum value in the tree.
 * In other words it returns the right-most located node in the binary search tree.
 *
 * @param bst The root of the binary search tree.
 *
 * @return The maximum node in the tree.
 */
bst_node *maxnode(bst_node *bst);

/**
 * Calculates the height of the tree from the root and returns it.
 *
 * @param bst The root of the binary search tree.
 *
 * @return The height of the tree.
 */
size_t height(bst_node *bst);

/**
 * Iterates the tree in "preorder" order and calls a callback function with each iteration.
 *
 * @param bst The root of the binary search tree.
 * @param iterator The function's pointer to iterate each node in the tree.
 *
 */
void iterate_preorder(bst_node *bst, void (*iterator)(const void *value));

/**
 * Iterates the tree in "inorder" order and calls a callback function with each iteration.
 *
 * @param bst The root of the binary search tree.
 * @param iterator The function's pointer to iterate each node in the tree.
 *
 */
void iterate_inorder(bst_node *bst, void (*iterator)(const void *value));

/**
 * Iterates the tree in "postorder" order and calls a callback function with each iteration.
 *
 * @param bst The root of the binary search tree.
 * @param iterator The function's pointer to iterate each node in the tree.
 *
 */
void iterate_postorder(bst_node *bst, void (*iterator)(const void *value));

/**
 * Frees the entire tree from memory recursively.
 *
 * @param bst The root of the binary search tree.
 */
void freetree(bst_node **bst);

#endif
