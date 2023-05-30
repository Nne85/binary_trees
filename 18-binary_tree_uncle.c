#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 *
 * @node: A pointer to the node to find the uncle of.
 *
 * Return: A pointer to the uncle node, or NULL if node is NULL,
 * the parent is NULL, the grandparent is NULL, or if node has no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* If node is NULL or the parent is NULL, return NULL */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* If the grandparent doesn't exist, return NULL */
	if (node->parent->parent == NULL)
		return (NULL);

	/* return right sibling uncle*/
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);

	/* return the left sibiling uncle*/
	if (node->parent == node->parent->parent->right)
		return (node->parent->parent->left);

	/* If node is not a child parent or the grandparent,return NULL */
	return (NULL);
}
