# include "binary_trees.h"
# include <stdio.h>
/**
 * binary_tree_levelorder -  a function that goes through
 * a binary tree using level-order traversal
 *
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	static size_t count = 1, i = 1, flag = 1;

	if (tree == NULL || func == NULL)
		return;
	if (i == count)
	{
		func(tree->n);
		flag = 2;
	}
	if (tree->left != NULL)
	{
		count++;
		binary_tree_levelorder(tree->left, func);
		count--;
	}
	if (tree->right != NULL)
	{
		count++;
		binary_tree_levelorder(tree->right, func);
		count--;
	}
	if (count == 1)
	{
		if (flag == 1)
			return;
		i++;
		flag = 1;
		binary_tree_levelorder(tree, func);
	}
}
