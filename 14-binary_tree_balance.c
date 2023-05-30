#include "binary_trees.h"

/**
 * binary_tree_height_1 - measures the hight of the tree
 * @tree:pointer to the root node of the tree
 * Return: 0 if tree is NULL else the hight
 */
int binary_tree_height_1(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = binary_tree_height_1(tree->left);
	right_height = binary_tree_height_1(tree->right);
	if (left_height >= right_height)
		return (left_height + 1);

	return (right_height + 1);

}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: 0 or balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height_1(tree->left);
	right_height = binary_tree_height_1(tree->right);
	return (left_height - right_height);
}
