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
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *tmp = NULL, *curr = NULL;

	tmp = first;
	curr = second;
	if (tmp == NULL || curr  == NULL)
		return (NULL);
	if (tmp->parent == NULL || curr->parent == NULL)
		return (NULL);
	
	while (tmp->parent != NULL)
	{
		curr = second;
		while (curr->parent != NULL)
		{
			if (tmp->parent == curr->parent)
				return (tmp->parent);
			curr = curr->parent;
		}
		tmp = tmp->parent;
	}
	return (NULL);
}
