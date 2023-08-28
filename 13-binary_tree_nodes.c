# include "binary_trees.h"
/**
 * binary_tree_nodes - a function that counts the
 * nodes with at least 1 child in a binary tree
 *
 * @tree: pointer to the root node of
 * the tree to count the number of nodes
 *
 * Return: number of nodes with at least 1 child
 * If tree is NULL, the function must return 0
 * A NULL pointer is not a node
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	static size_t count = 1;
	static size_t number = 1;
	size_t p;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL || tree->right != NULL)
		number++;
	if (tree->left != NULL)
	{
		count++;
		binary_tree_nodes(tree->left);
		count--;
	}
	if (tree->right != NULL)
	{
		count++;
		binary_tree_nodes(tree->right);
		count--;
	}
	if (count == 1)
	{
		p = number - 1;
		number = 1;
		return (p);
	}
	return (0);
}
