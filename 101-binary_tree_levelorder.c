#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Perform level-order traversal of a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to the function to call for each node
 *
 * Description: This function traverses the binary tree in level-order
 * (breadth-first search) and applies the provided function to each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Create a queue to store the nodes */
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);

	if (queue == NULL)
		return;

	int front = 0;
	/* Index of the front element in the queue */
	int rear = 0;
	/* Index of the rear element in the queue */

	queue[rear] = (binary_tree_t *)tree;
	rear++;

	while (front < rear)
	{
		binary_tree_t *current = queue[front];

		front++;

		func(current->n);

		if (current->left != NULL)
		{
			queue[rear] = current->left;
			rear++;
		}

		if (current->right != NULL)
		{
			queue[rear] = current->right;
			rear++;
		}
	}

	free(queue);
}
