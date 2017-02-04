#include "avltree.h"

bst_node *rotate_leftleft(bst_node *bst)
{
    bst_node *x = bst;
    bst_node *y = bst->left;
    
    x->left = y->right;
    y->right = x;
    
    return y;
}

bst_node *rotate_leftright(bst_node *bst)
{
    bst_node *x = bst;
    bst_node *y = bst->left;
    bst_node *z = y->right;
    
    x->left = z->right;
    y->right = z->left;
    z->left = y;
    z->right = x;
    
    return z;
}

bst_node *rotate_rightright(bst_node *node)
{
    bst_node *x = node;
    bst_node *y = node->right;
    
    x->right = y->left;
    y->left = x;
    
    return y;
}

bst_node *rotate_rightleft(bst_node *node)
{
    bst_node *x = node;
    bst_node *y = node->right;
    bst_node *z = y->left;
    
    x->right = z->left;
    y->left = z->right;
    z->right = y;
    z->left = x;
    
    return z;
}

int balance(bst_node *bst)
{
    int balance = 0;
    if (bst->left)
        balance += height(bst->left);
    if (bst->right)
        balance -= height(bst->right);
    
    return balance;
}

void avlbalance(bst_node **bst)
{
    
}

void balancedinsert(bst_node **bst, data_t value)
{
    insert(bst, value);
    avlbalance(bst);
}
