#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current, *parent;

	if (tree == NULL)
		return (NULL);

	/* If the tree is empty, create the root node */
	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}

	current = *tree;
	parent = NULL;

	/* Find the appropriate position to insert the value */
	while (current != NULL)
	{
		parent = current;

		if (value == current->n)
			return (NULL); /* Value already exists, ignore */

		if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}

	/* Create the new node with the given value */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL); /* Failed to allocate memory for the new node */

	/* Insert the new node as the left or right child of the parent */
	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}
