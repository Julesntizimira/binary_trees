# include "binary_trees.h"
/**
 * binary_tree_rotate_left - function that performs a
 * right-rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *curr = NULL, *tmp = NULL;

	if (tree == NULL)
		return (NULL);

	if (tree->right == NULL)
		return (tree);

	curr = tree->right;
	tmp = curr->left;

	curr->parent = tree->parent;

	if (curr->parent)
	{
		if (curr->n > curr->parent->n)
			curr->parent->right = curr;
		else
			curr->parent->left = curr;
	}
	tree->parent = curr;

	if (tmp != NULL)
		tmp->parent = tree;

	curr->left = tree;
	tree->right = tmp;



	return (curr);
}
