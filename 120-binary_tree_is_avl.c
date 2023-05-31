#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measure the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			height_left = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			height_right = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((height_left > height_right ? height_left : height_right));
	}
}

/**
 * binary_tree_is_bst_bal - Check if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 * @min: Minimum value allowed in the tree (previous max)
 * @max: Maximum value allowed in the tree (previous min)
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst_bal(const binary_tree_t *tree, int min, int max)
{
	size_t height_left, height_right, balancecheck;

	if (tree != NULL)
	{
		if (tree->n <= min || tree->n >= max)
		{
			return (0);
		}

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);
	balancecheck = height_left > height_right ? height_left -
		height_right : height_right - height_left;

	if (balancecheck > 1)
	{
		return (0);
	}
	return (binary_tree_is_bst_bal(tree->left, min, tree->n - 1) &&
			binary_tree_is_bst_bal(tree->right, tree->n + 1, max));
	}
	return (1);

}

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (binary_tree_is_bst_bal(tree, INT_MIN, INT_MAX));

	/*
	 * if (!binary_tree_is_bst_bal(tree, INT_MIN, INT_MAX))
	 * return (0);
	 * left_height = binary_tree_height(tree->left);
	 * right_height = binary_tree_height(tree->right);
	 * height_diff = left_height - right_height;
	 * if (height_diff < -1 || height_diff > 1)
	 * return (0);
	 * if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
	 * return (0);
	 * return (1);
	 */
}
