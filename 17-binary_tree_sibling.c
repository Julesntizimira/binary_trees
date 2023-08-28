# include "binary_trees.h"

/**
 * binary_tree_sibling - a function that finds
 * the sibling of a node
 *
 * @node: is a pointer to the node to
 * find the sibling
 *
 * Return: a pointer to the sibling node
 * If node is NULL or the parent is NULL, return NULL
 * If node has no sibling, return NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *temp = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	temp = node->parent;
	if (temp->left == NULL || temp->right == NULL)
		return (NULL);

	if (temp->left != node)
		return (temp->left);
	else
		return (temp->right);
}
