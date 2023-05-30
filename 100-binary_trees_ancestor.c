#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node, or NULL if no common
 *         ancestor was found or if either node is NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancestor1, *ancestor2;

	/* If either node is NULL, return NULL */
	if (first == NULL || second == NULL)
		return (NULL);

	/* Handle the case when first and second are the same node */
	if (first == second)
		return ((binary_tree_t *)first);

	/* Traverse up from first and second to find their ancestors */
	ancestor1 = (binary_tree_t *)first;
	ancestor2 = (binary_tree_t *)second;

	while (ancestor1 != ancestor2)
	{
		/* Move up the tree for ancestor1 */
		if (ancestor1->parent != NULL)
			ancestor1 = ancestor1->parent;
		else
			ancestor1 = (binary_tree_t *)second;
		/* Move up the tree for ancestor2 */
		if (ancestor2->parent != NULL)
			ancestor2 = ancestor2->parent;
		else
			ancestor2 = (binary_tree_t *)first;
	}

	return (ancestor1);
}
