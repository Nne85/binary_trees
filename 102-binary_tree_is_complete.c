#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Check if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_complete(tree, 0, count_nodes(tree)));
}

/**
 * count_nodes - Count the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The number of nodes in the tree
 */
size_t count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete - Recursive function to check if a binary tree is complete
 * @tree: Pointer to the current node of the tree
 * @index: Index of the current node
 * @node_count: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, node_count) &&
		is_complete(tree->right, 2 * index + 2, node_count));
}
