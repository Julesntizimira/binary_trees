# include "binary_trees.h"
/**
 * binary_tree_is_full - a function that checks
 * if a binary tree is full
 *
 * @tree:  pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full and 0 otherwise\
 * If tree is NULL, your function must return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	static int count = 1;
	static int full = 1;
	int p, i = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		i++;
	if (tree->right != NULL)
		i++;
	if (i == 1)
	{
		full = 0;
		if (count == 1)
		{
			p = full;
			full = 1;
			return (p);
		}
		return (full);
	}
	if (tree->left != NULL)
	{
		count++;
		binary_tree_is_full(tree->left);
		count--;
	}
	if (tree->right != NULL)
	{
		count++;
		binary_tree_is_full(tree->right);
		count--;
	}
	if (count == 1)
	{
		p = full;
		full = 1;
		return (p);
	}
	return (full);
}
