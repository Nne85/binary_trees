#include "binary_trees.h"

/**
 * is_bst_helper - Recursive helper function to check if a
 * binary tree is a valid BST.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Pointer to the minimum value that the nodes in the subtree can take.
 * @max: Pointer to the maximum value that the nodes in the subtree can take.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst_helper(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if ((min != NULL && tree->n <= min->n) ||
			(max != NULL && tree->n >= max->n))
		return (0);

	return (is_bst_helper(tree->left, min, tree) &&
			is_bst_helper(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
        return (is_bst_helper(tree, NULL, NULL));
}
