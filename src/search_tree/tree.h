#pragma once

#include <stdbool.h>

typedef struct tree_element tree_element_t;
typedef struct tree tree_t;

/*!
 * \brief Create a new empty tree with a type data_t
 *        that satisfies sizeof(data_t) = data_size.
 *        The tree stores elements of the type data_t.
 *        Call tree_destroy for freeing ressources.
 * \param [in] data_size the size in bytes of each element
 * \return a new empty tree
 */
tree_t tree_create(int data_size);

/*!
 * \brief Free the ressources of a tree.
 * \param [in] tree pointer to the tree
 */
void tree_destroy(tree_t *tree);

/*!
 * \brief Checks whether the tree holds no elements.
 * \param [in] tree pointer to the tree
 * \return true iff the tree is empty
 */
bool tree_empty(tree_t *tree);

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
void tree_insert_left(tree_t *tree, tree_element_t *parent, void *data_ptr);

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
