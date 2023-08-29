# include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *tmp = NULL, *curr = NULL;

	tmp = (binary_tree_t *)first;
	curr = (binary_tree_t *)second;
	if (tmp == NULL || curr  == NULL)
		return (NULL);

	while (tmp != NULL)
	{
		curr = (binary_tree_t *)second;
		while (curr != NULL)
		{
			if (tmp == curr)
				return (tmp);
			curr = curr->parent;
		}
		tmp = tmp->parent;
	}
	return (NULL);
}
