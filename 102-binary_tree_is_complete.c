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
	static int count = 1, check = 1, check1 = 1, flag = 1, z = 1, k = 1;
	int j = 0, i = 1;

	if (tree == NULL)
		return (0);
	j = sides_check(tree);
	if ((check1 == 0 && count <= k - 2 && j != 3) ||
			((check == 0 && count >= z && j != 0) || (j == 2)) ||
			(check1 == 0 && check == 0 && k != z + 1) ||
			(check1 == 0 && count > k))
		flag = 0;
	if (flag == 0 && count == 1)
	{
		flag = 1;
		check = 1;
		check1 = 1;
		z = 1;
		k = 1;
		return (0);
	}
	if (flag == 0)
		return (0);
	if (j == 1 && check == 1)
	{
		check = 0;
		z = count;
	}
	if (j == 0 && check1 == 1)
	{
		k = count;
		check1 = 0;
	}
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
	if (count == 1)
	{
		i = flag;
		flag = 1;
		check = 1;
		check1 = 1;
		z = 1;
		k = 1;
	}
	return (i);
}
