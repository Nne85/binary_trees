#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left, right;

	/* If tree is NULL, it is not full */
	if (tree == NULL)
		return (0);

	/* If both children are NULL, it is a leaf node and therefore full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left = binary_tree_is_full(tree->left);
	right = binary_tree_is_full(tree->right);
	/* If both children are present, recursively check if they are full */
	if (tree->left && tree->right)
		return (left && right);

	/* If only one child is present, it is not full */
	return (0);
}
