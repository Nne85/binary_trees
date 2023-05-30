#include "binary_trees.h"

#include "binary_trees.h"
/**
 * binary_tree_is_leaf - check node leaf or not
 * @node: node to check
 * Return: 1 if node if leaf 0 if not
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	else if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (right_height <= left_height)
		return (left_height + 1);
	return (right_height + 1);
}

#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, right_height, left, right;

	/* If tree is NULL, it is not perfect */
	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* If the left and right subtrees have different heights, it is not perfect */
	if (left_height != right_height)
		return (0);
	/* If the tree is a leaf node, it is perfect */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left = binary_tree_is_perfect(tree->left);
	right = binary_tree_is_perfect(tree->right);

	/* Recursively check if the left and right subtrees are perfect */
	return (left && right);
}
