# include "binary_trees.h"

/**
 * binary_tree_uncle - a function that finds
 * the uncle of a node
 *
 * @node: is a pointer to the node to
 * find the uncle
 *
 * Return: a pointer to the uncle node
 * If node is NULL or the parent is NULL, return NULL
 * If node has no sibling, return NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *temp = NULL, *par = NULL;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	temp = node->parent->parent;
	par = node->parent;
	if (temp->left == NULL || temp->right == NULL)
		return (NULL);

	if (temp->left != par)
		return (temp->left);
	else
		return (temp->right);
}
