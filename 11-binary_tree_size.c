# include "binary_trees.h"
/**
 * binary_tree_size - function that measures the
 * size of a binary tree
 *
 * @tree: a pointer to the root node of the
 * tree to measure the size
 *
 * Return: the size of a binary tree
 * if tree is NULL, the function must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	static size_t count = 1;
	static size_t number = 1;
	size_t p;

	if (tree == NULL)
		return (0);
	number++;
	if (tree->left != NULL)
	{
		count++;
		binary_tree_size(tree->left);
		count--;
	}
	if (tree->right != NULL)
	{
		count++;
		binary_tree_size(tree->right);
		count--;
	}
	if (count == 1)
	{
		p = number - 1;
		number = 1;
		return (p);
	}
	return (count);
}
