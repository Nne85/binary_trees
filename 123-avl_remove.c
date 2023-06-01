#include "binary_trees.h"
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * binary_tree_min - Finds the minimum value in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Pointer to the node containing the minimum value,
 *         or NULL if the tree is empty
 */
binary_tree_t *binary_tree_min(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);

	while (tree->left != NULL)
		tree = tree->left;

	return ((binary_tree_t *)tree);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + MAX(left_height, right_height));
}
/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node of the tree after removing the value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			avl_t *temp = root->left ? root->left : root->right;

			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{
			avl_t *temp = binary_tree_min(root->right);

			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}

	if (root == NULL)
		return (NULL);

	root->height = 1 + MAX(binary_tree_height(root->left),
			binary_tree_height(root->right));

	int balance = binary_tree_balance(root);

	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));

	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}

	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));

	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}
