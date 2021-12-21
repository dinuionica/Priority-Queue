#include "AVL.h"

/* the function that adds a new value in the avl */
void AVL::add(int value) {
    root = add_util(root, value);
}

/* the function that removes the max value from the avl */
void AVL::remove_max() {
    /* obtaining and deleting the maximum element */
    Node *node = max_node(root);
    root = remove_util(root, node->data);
}

/* the function that returns the maximum element */
int AVL::max_element() {
    Node *node = max_node(root);
    return node->data;
}

/* the function that prints the elements in preorder */
void AVL::preorder() {
    preorder_util(root);
}

/* the function that calculates the height of a node */
int AVL::height(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

/* the auxiliary function for displaying items in preorder */
void AVL::preorder_util(Node *root) {
    Node *current = root;
    /* print the data of the current node */
    std::cout << current->data << " ";
    /* scroll left subtree */
    preorder_util(current->left);
    /* scroll right  subtree */
    preorder_util(current->right);
}

/* the function that creates a new node */
Node *AVL::create_node(int value) {
    Node *node = new Node();
    node->data = value;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* the function that makes a right rotation of a node*/
Node *AVL::rotate_right(Node *node) {
    Node *left_son = node->left;
    Node *left_right_son = left_son->right;
    Node *right_son = node;

    node = left_son;
    node->right = right_son;
    node->right->left = left_right_son;

    /* fix height */
    node->right->height = 1 + std::max(height(node->right->left),
                                       height(node->right->right));
    node->height = 1 + std::max(height(node->left),
                                height(node->right));

    return left_son;
}

/* the function that makes a left rotation of a node*/
Node *AVL::rotate_left(Node *node) {
    Node *right_son = node->right;
    Node *right_left_son = right_son->left;
    Node *left_son = node;

    node = right_son;
    node->left = left_son;
    node->left->right = right_left_son;

    /* fix height */
    node->left->height = 1 + std::max(height(node->left->left),
                                      height(node->left->right));
    node->height = 1 + std::max(height(node->left),
                                height(node->right));

    return right_son;
}

/* the function that calculates the balance factor of a node */
int AVL::get_balance(Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

/* the function that balances the avl */
Node *AVL::fix_avl(Node *node) {
    int balance = get_balance(node);
    /* tree balancing depending on factor and heights */
    if (balance > 1 && height(node->left) >= height(node->right)) {
        return rotate_right(node);
    }

    else if (balance > 1 && height(node->left) <= height(node->right)) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    else if (balance < -1 && height(node->right) >= height(node->left)) {
        return rotate_left(node);
    }

    else if (balance < -1 && height(node->right) <= height(node->left)) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}

/* the function that returns the node with maximum value */
Node *AVL::max_node(Node *root) {
    Node *current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}

/* the function that returns the node with minimum value */
Node *AVL::min_node(Node *root) {
    Node *current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
/* the auxiliary function used to add a new element */
Node *AVL::add_util(Node *node, int value) {
    if (node == NULL) {
        Node *root = create_node(value);
        return root;
    }

    if (value > node->data) {
        /* insert in the right subtree */
        node->right = add_util(node->right, value);
    } else if (value < node->data) {
        /* insert in the left subtree */
        node->left = add_util(node->left, value);
    } else {
        return node;
    }

    /* update the height */
    node->height = std::max(height(node->left), height(node->right)) + 1;
    /* tree balancing */
    node = fix_avl(node);
    return node;
}

/* the auxiliary function used to remove an element */
Node *AVL::remove_util(Node *node, int value) {
    if (node == NULL) {
        return NULL;
    } else if (value > node->data) {
        /* remove from the right subtree */
        node->right = remove_util(node->right, value);
    } else if (value < node->data) {
        /* remove from the right subtree */
        node->left = remove_util(node->left, value);
    } else {
        if (node->right == NULL) {
            Node *left_node = node->left;
            delete (node);
            node = left_node;
        } else if (node->left == NULL) {
            Node *right_node = node->right;
            delete (node);
            node = right_node;
        } else {
            /* determine the minimum node */
            Node *min_value_node = min_node(node->right);
            /* copy the successor's data to this node */
            node->data = min_value_node->data;
            /* delete recursively the successor */
            node->right = remove_util(node->right, min_value_node->data);
        }
    }
    if (node == NULL) {
        return node;
    }

    /* update the height */
    node->height = 1 + std::max(height(node->left), height(node->right));
    /* tree balancing */
    node = fix_avl(node);
    return node;
}
