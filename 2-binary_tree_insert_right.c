# include "binary_trees.h"
/**
 * binary_tree_insert_right - a function that creates a binary tree node
 *
 * @parent: pointer to the parent node of the node to create
 * @value: the value to put in the new node
 *
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode = NULL;

	if (parent == NULL)
		return (NULL);

	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
		return (NULL);

	newnode->right = parent->right;
	newnode->left = NULL;
	newnode->n = value;
	newnode->parent = parent;

	parent->right = newnode;
	if (newnode->right != NULL)
		newnode->right->parent = newnode;

	return (newnode);
}
