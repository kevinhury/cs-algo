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

int getbalance(bst_node *bst)
{
    if (!bst) return 0;
    
    int balance = 0;
    if (bst->left)
        balance += height(bst->left);
    if (bst->right)
        balance -= height(bst->right);
    
    return balance;
}

void avlbalance(bst_node **bst)
{
    bst_node *newroot, *node = *bst;
    int balance;
    
    if (node->left) {
        avlbalance(&(node->left));
    }
    if (node->right) {
        avlbalance(&(node->right));
    }
    
    balance = getbalance(node);
    
    if (balance >= 2) {
        if (getbalance(node->left) <= -1)
            newroot = rotate_leftright(node);
        else
            newroot = rotate_leftleft(node);
            
    } else if (balance <= -2) {
        if (getbalance(node->right) >= -1)
            newroot = rotate_rightleft(node);
        else
            newroot = rotate_rightright(node);
    } else {
        newroot = node;
    }
    
    *bst = newroot;
}

void avlinsert(bst_node **bst, data_t value)
{
    insert(bst, value);
    avlbalance(bst);
}
