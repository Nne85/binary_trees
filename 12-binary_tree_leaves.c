#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree:  pointer to the root node of the tree to count the number of leaves
 * Return: 0 if tree is NULL else the size leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_height = binary_tree_leaves(tree->left);
	right_height = binary_tree_leaves(tree->right);

	return (left_height + right_height);
}
