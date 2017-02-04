#include "binarysearchtree.h"

bst_node *createnode(data_t value)
{
    bst_node *node = malloc(sizeof(bst_node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

void insert(bst_node **bst, data_t value)
{
    bst_node *node = *bst;
    if (node == NULL) {
        *bst = createnode(value);
    } else {
        if (value < node->value) {
            if (node->left != NULL) insert(&node->left, value);
            else node->left = createnode(value);
        } else if (value > node->value) {
            if (node->right != NULL) insert(&node->right, value);
            else node->right = createnode(value);
        }
    }
}

void removenode(bst_node **bst, data_t value)
{
    bst_node *node = *bst;
    bst_node *min;
    if (value > node->value) {
        removenode(&node->right, value);
    } else if (value < node->value) {
        removenode(&node->left, value);
    } else {
        min = minnode(node);
        
    }
}

bst_node *search(bst_node *bst, data_t value)
{
    if (bst == NULL) return NULL;
    
    if (value > bst->value) {
        return search(bst->right, value);
    } else if (value < bst->value) {
        return search(bst->left, value);
    } else {
        return bst;
    }
}

bst_node *minnode(bst_node *bst)
{
    if (bst->left != NULL) {
        return minnode(bst->left);
    } else {
        return bst;
    }
}

bst_node *maxnode(bst_node *bst)
{
    if (bst->right != NULL) {
        return maxnode(bst->right);
    } else {
        return bst;
    }
}

void print_preorder(bst_node *bst)
{
    if (bst == NULL) return;

    printf("%d ", bst->value);
    print_preorder(bst->left);
    print_preorder(bst->right);
}

void print_inorder(bst_node *bst)
{
    if (bst == NULL) return;

    print_inorder(bst->left);
    printf("%d ", bst->value);
    print_inorder(bst->right);
}

void print_postorder(bst_node *bst)
{
    if (bst == NULL) return;

    print_postorder(bst->left);
    print_postorder(bst->right);
    printf("%d ", bst->value);
}

void print_by_level(bst_node *bst)
{
    // Unimplemented
    exit(1);
}

void freetree(bst_node **bst)
{
    if (*bst == NULL) return;

    freetree(&((*bst)->left));
    freetree(&((*bst)->right));
    free(*bst);
    *bst = NULL;
}
