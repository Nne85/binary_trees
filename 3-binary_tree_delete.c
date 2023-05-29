#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree:  pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* Post-order traversal to delete nodes recursively */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	/* Free and Delete the current node */
	free(tree);
}
