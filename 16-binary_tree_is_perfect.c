# include "binary_trees.h"
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
/**
 * power - compute a power b
 * @a: input
 * @b: input
 * Return: a power b
 */
int power(int a, int b)
{
	int i = 1, product = a;

	while (i < b)
	{
		product *= a;
		i++;
	}
	return (product);
}
/**
 * binary_tree_is_perfect - a function that checks if
 * a binary tree is perfect
 *
 * @tree: a pointer to the root node of
 * the tree to check
 *
 * Return: 1 if is perfect, else 0
 * if tree is NULL, the function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = 0, size = 0;

	if (tree == NULL)
		return (0);
	size = binary_tree_size(tree);
	height = binary_tree_height(tree);

	if (size == power(2, (height + 1)) - 1)
		return (1);
	return (0);
}
