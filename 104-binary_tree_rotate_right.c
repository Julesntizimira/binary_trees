# include "binary_trees.h"
/**
 * binary_tree_rotate_right - function that performs a
 * right-rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *curr = NULL, *tmp = NULL;

	if (tree == NULL)
		return (NULL);

	if (tree->left == NULL)
		return (tree);

	curr = tree->left;
	tmp = curr->right;

	curr->parent = tree->parent;
	tree->parent = curr;

	if (tmp != NULL)
		tmp->parent = tree;

	curr->right = tree;
	tree->left = tmp;

	return (curr);
}
