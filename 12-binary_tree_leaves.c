# include "binary_trees.h"
/**
 * binary_tree_leaves - function that counts the
 * leaves in a binary tree
 *
 * @tree:  a pointer to the root node of the
 * tree to count the number of leaves
 *
 * Return: number of leaves in a binary tree
 * If tree is NULL, the function must return 0
 * A NULL pointer is not a leaf
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	static size_t number = 1;
	static size_t count = 1;
	size_t p;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
	{
		number++;
		binary_tree_leaves(tree->left);
		number--;
	}
	if (tree->right != NULL)
	{
		number++;
		binary_tree_leaves(tree->right);
		number--;
	}
	if (tree->left == NULL && tree->right == NULL)
		count++;
	if (number == 1)
	{
		p = count - 1;
		count = 1;
		return (p);
	}
	return (count);
}
