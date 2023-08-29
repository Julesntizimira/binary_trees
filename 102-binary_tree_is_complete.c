# include "binary_trees.h"
/**
 * sides_check - check node children both sides
 * @tree: the node to check
 * Return: int
 */
int sides_check(const binary_tree_t *tree)
{
	int j = 0;

	if (tree->left != NULL)
		j += 1;
	if (tree->right != NULL)
		j += 2;
	return (j);
}
/**
 * binary_tree_is_complete - a function that checks
 * if a binary tree is complete
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a complete
 * binary tree or 0 otherwise
 *
 * If tree is NULL, your function must return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	static int count = 1, height = 1, check = 1, flag = 1;
	int j = 0;

	if (tree == NULL)
		return (0);
	if (count > height)
		height = count;
	j = sides_check(tree);
	if ((check == 0 && count == (height - 1) && j != 0) || (j == 2))
		flag = 0;
	if (check == 0 && j != 3 &&  count < height - 1)
		flag = 0;
	if (flag == 0 && count == 1)
	{
		flag = 1;
		check = 1;
		return (0);
	}
	if (flag == 0)
		return (0);
	if (j == 1)
		check = 0;
	if (tree->left != NULL)
	{
		count++;
		binary_tree_is_complete(tree->left);
		count--;
	}
	if (tree->right != NULL)
	{
		count++;
		binary_tree_is_complete(tree->right);
		count--;
	}
	if (count == 1 && flag == 0)
	{
		flag = 1;
		check = 1;
		return (0);
	}
	return (1);
}
