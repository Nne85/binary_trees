#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 *
 * @node: A pointer to the node to find the sibling of.
 *
 * Return: A pointer to the sibling node, or NULL if node is NULL,
 *         the parent is NULL, or if node has no sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* If node is NULL or the parent is NULL, return NULL */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* If node is the left child, return the right sibling (or NULL) */
	if (node->parent->left == node)
		return (node->parent->right);

	/* If node is the right child, return the left sibling (or NULL) */
	if (node->parent->right == node)
		return (node->parent->left);

	/* If node is not a child of its parent, return NULL */
	return (NULL);
}
