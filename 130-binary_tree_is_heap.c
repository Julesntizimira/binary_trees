# include "binary_trees.h"
/**
 * reset_flags - reset all static variable in
 * binary_tree_is_complete()
 *
 * @flag: input
 * @check: input
 * @check1: input
 * @z: input
 * @k: input
 */
void reset_flags(int *check, int *check1, int *flag, int *z, int *k)
{
	*flag = 1;
	*check = 1;
	*check1 = 1;
	*z = 1;
	*k = 1;
}
/**
 * sides_check - check node children both sides
 * @tree: the node to check
 *
 * @count: input
 * @flag: input
 * @check: input
 * @check1: input
 * @z: input
 * @k: input
 * Return: int
 */
int sides_check(const binary_tree_t *tree, int *count,
		int *check, int *check1, int *flag, int *z, int *k)
{
	int j = 0;

	if (tree->left != NULL)
		j += 1;
	if (tree->right != NULL)
		j += 2;
	if ((*check1 == 0 && *count <= *k - 2 && j != 3) ||
			((*check == 0 && *count >= *z && j != 0) || (j == 2)) ||
			(*check1 == 0 && *check == 0 && *k != *z + 1) ||
			(*check1 == 0 && *count > *k))
		*flag = 0;
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
	j = sides_check(tree, &count, &check, &check1, &flag, &z, &k);
	if (flag == 0 && count == 1)
		reset_flags(&check, &check1, &flag, &z, &k);
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
		reset_flags(&check, &check1, &flag, &z, &k);
	}
	return (i);
}

/**
 * is_max_helper - function that checks if every
 * node is max to all its childen
 *
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 on success or 0 otherwise
 */
int is_max_helper(const binary_tree_t *tree)
{
	static size_t is_max = 1, cnt = 1;

	int z = 1;

	if (tree->left)
	{
		if (tree->n < tree->left->n)
			is_max = 0;
	}
	if (tree->right)
	{
		if (tree->n < tree->right->n)
			is_max = 0;
	}
	if (is_max == 0)
		return (0);

	if (tree->left)
	{
		cnt++;
		is_max_helper(tree->left);
		cnt--;
	}
	if (tree->right)
	{
		cnt++;
		is_max_helper(tree->right);
		cnt--;
	}
	if (cnt == 1)
	{
		z = is_max;
		is_max = 1;
	}
	return (z);

}
/**
 * binary_tree_is_heap - function that checks if a binary tree
 * is a valid Max Binary Heap
 *
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (is_max_helper(tree) == 0)
		return (0);

	return (binary_tree_is_complete(tree));
}
