#pragma once

typedef struct tree_element {
    void *data_ptr;
    struct tree_element *left;
    struct tree_element *right;
} tree_element_t;

typedef struct tree {
    int data_size;
    tree_element_t *root;
} tree_t;
