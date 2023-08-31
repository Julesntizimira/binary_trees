# include "binary_trees.h"
# include <stdio.h>
/**
 * binary_tree_height - function that measures the
 * height of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: return 0 if tree is NULL, else return tree height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	static size_t height = 1;
	static size_t count = 1;
	size_t p;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
	{
		count++;
		binary_tree_height(tree->left);
		count--;
	}
	if (tree->right != NULL)
	{
		count++;
		binary_tree_height(tree->right);
		count--;
	}
	if (count > height)
		height = count;

	if (count == 1)
	{
		p = height - 1;
		height = 1;
		return (p);
	}
	return (count);
}
/**
 * binary_tree_balance - a function that measures
 * the balance factor of a binary tree
 *
 * @tree: a pointer to the root node of the
 * tree to measure the balance factor
 *
 * Return: the balance factor of a binary tree
 * If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int rt, lt, b_factor;

	if (tree == NULL)
		return (0);
	lt = (int)binary_tree_height(tree->left);
	if (tree->left != NULL)
		lt++;
	rt = (int)binary_tree_height(tree->right);
	if (tree->right != NULL)
		rt++;
	b_factor = lt - rt;

	return (b_factor);
}
