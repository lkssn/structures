#include "tree.h"
#include "tree_priv.h"
#include <memory.h>


tree_t tree_create(int data_size) {
    tree_t tree = {
        .data_size = data_size,
        .root = NULL
    };

    return tree;
}

/*!
 * \brief Free the ressources of a tree.
 * \param [in] tree pointer to the tree
 */
void tree_destroy(tree_t *tree) {
    // TODO: walk the tree and delete nodes efficiently
    /* tree_element_t *element = tree->root;
    
    while (element) {
        tree_element_t *left = element->left;
        tree_element_t *right = element->right;
    } */
}

/*!
 * \brief Checks whether the tree holds no elements.
 * \param [in] tree pointer to the tree
 * \return true iff the tree is empty
 */
bool tree_empty(tree_t *tree) {
    return !tree->root;
}

/*!
 * \brief Try to insert a new element as the left child of a parent node.
          The parent must be a node in the tree.
          Insertion is successfull, if the left child does not exist yet.
          Otherwise it fails.
 * \param [in] tree pointer to the tree
 * \param [in] parent pointer to the parent node
 * \param [in] data_ptr pointer of the data for copying in
 * \return true iff insertion was sucessfull
 */
void tree_insert_left(tree_t *tree, tree_element_t *parent, void *data_ptr) {
    tree_element_t *
    idc
}

/*!
 * \brief Try to insert a new element as the right child of a parent node.
          The parent must be a node in the tree.
          Insertion is successfull, if the right child does not exist yet.
          Otherwise it fails.
 * \param [in] tree pointer to the tree
 * \param [in] parent pointer to the parent node
 * \param [in] data_ptr pointer of the data for copying in
 * \return true iff insertion was sucessfull
 */
void tree_insert_right(tree_t *tree, tree_element_t *parent, void *data_ptr);

/*!
 * \brief Try to remove the left child of a parent node.
          The parent must be a node in the tree.
          Removal is successfull, if the left child exists.
          Otherwise it fails.
 * \param [in] tree pointer to the tree
 * \param [in] parent pointer to the parent node
 * \param [out] data_ptr pointer of the data for copying out (not empty iff success)
 * \return true iff removal was sucessfull
 */
bool tree_remove_left(tree_t *tree, tree_element_t *parent, void *data_ptr);

/*!
 * \brief Try to remove the right child of a parent node.
          The parent must be a node in the tree.
          Removal is successfull, if the right child exists.
          Otherwise it fails.
 * \param [in] tree pointer to the tree
 * \param [in] parent pointer to the parent node
 * \param [out] data_ptr pointer of the data for copying out (not empty iff success)
 * \return true iff removal was sucessfull
 */
bool tree_remove_right(tree_t *tree, tree_element_t *parent, void *data_ptr);

/*!
 * \brief Apply a fold operation to the nodes of a tree with an initial value and
          a combining function.
          The order of the nodes is not specified and therefore should not be meaningful.
          The function gets as the first argument the pointer to the accumulator
          and as the second argument a pointer to the data_t element of the node.
 * \param [in] tree pointer to the tree
 * \param [in] fn combining function
 * \param [in,out] s pointer to the accumulator with some initial value at the start
 */
void tree_fold(tree_t *tree, void (*fn)(void*, void*), void *s);