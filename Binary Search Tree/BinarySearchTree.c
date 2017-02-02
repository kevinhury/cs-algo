#include "BinarySearchTree.h"

void insert(bst_node** bst, data_type x)
{
    bst_node* t = *bst, *parent = NULL;
    while (t != NULL)
    {
        parent = t;
        if (x < t->data)
            t = t->left;
        else
            t = t->right;
    }
    
    bst_node *p = malloc(sizeof(bst_node));
    p->data = x;
    p->left = p->right = NULL;
    if (parent == NULL)
        *bst = p;
    else if (x < parent->data)
        parent->left = p;
    else if (x > parent->data)
        parent->right = p;
}

void print_preorder(bst_node *bst)
{
    if (bst == NULL) return;

    printf("%d", bst->data);
    print_preorder(bst->left);
    print_preorder(bst->right);
}

void print_inorder(bst_node *bst)
{
    if (bst == NULL) return;

    print_inorder(bst->left);
    printf("%d", bst->data);
    print_inorder(bst->right);
}

void print_postorder(bst_node *bst)
{
    if (bst == NULL) return;

    print_postorder(bst->left);
    print_postorder(bst->right);
    printf("%d", bst->data);
}

void print_by_level(bst_node *bst)
{
    // Unimplemented
    exit(1);
}

void clear_tree(bst_node **bst)
{
    if (*bst == NULL) return;

    clear_tree(&((*bst)->left));
    clear_tree(&((*bst)->right));
    free(*bst);
    *bst = NULL;
}
