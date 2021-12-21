#ifndef AVL_H
#define AVL_H

#include <iostream>

/* class of a avl node */
class Node {
   public:
    int data;
    Node *left;
    Node *right;
    int height;
};

/* class of a avl data structure */
class AVL {
   public:
    Node *root = NULL;

    void add(int value);

    void remove_max();

    int max_element();

    void preorder();

   private:
    int height(Node *node);

    void preorder_util(Node *node);

    Node *create_node(int value);

    int get_balance(Node *node);

    Node *rotate_right(Node *node);

    Node *rotate_left(Node *node);

    Node *fix_avl(Node *node);

    Node *add_util(Node *node, int value);

    Node *max_node(Node *node);

    Node *min_node(Node *root);

    Node *remove_util(Node *node, int value);
};

#endif /* AVL_H */
