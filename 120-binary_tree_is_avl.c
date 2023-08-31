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
 * binary_tree_balance_root - a function that measures
 * the balance factor of a binary tree from bottom-top
 * post order traversal
 * check if the whole tree is balanced
 *
 * @tree: a pointer to the root node of the
 * tree to measure the balance factor
 *
 * Return: the balance factor of a binary tree
 * If tree is NULL, return 0
 */
int binary_tree_balance_root(const binary_tree_t *tree)
{
	static int b_flag = 1, cnt = 1;
	int rt, lt, b_factor, j = 1;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
	{
		cnt++;
		binary_tree_balance_root(tree->left);
		cnt--;
	}
	if (tree->right != NULL)
	{
		cnt++;
		binary_tree_balance_root(tree->right);
		cnt--;
	}
	lt = (int)binary_tree_height(tree->left);
	if (tree->left != NULL)
		lt++;
	rt = (int)binary_tree_height(tree->right);
	if (tree->right != NULL)
		rt++;
	b_factor = lt - rt;

	if (b_factor > 1 || b_factor < -1)
		b_flag = 0;
	if (cnt == 1)
	{
		j = b_flag;
		b_flag = 1;
	}
	return (j);
}
/**
 * binary_tree_array - function that return a
 * tree as an array(inorder traversal)
 *
 * @tree: a pointer to the root node
 *
 * Return: array represantation of a tree
 * if tree is NULL, the function must return NULL
 */
int *binary_tree_array(const binary_tree_t *tree)
{
	static size_t count = 1, index = 1;
	static int bts_list[1024] = {0};

	if (tree == NULL)
		return (NULL);
	if (tree->left != NULL)
	{
		count++;
		binary_tree_array(tree->left);
		count--;
	}
	bts_list[index - 1] = tree->n;
	index++;
	if (tree->right != NULL)
	{
		count++;
		binary_tree_array(tree->right);
		count--;
	}
	if (count == 1)
	{
		bts_list[index] = 0;
		index = 1;
		return (bts_list);
	}
	return (bts_list);
}
/**
 * binary_tree_is_bst - function that checks if a binary tree
 * is a valid Binary Search Tree
 *
 * @tree:  is a pointer to the root node of the tree to check
 *
 * Return: return 1 if tree is a valid BST, and 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int *bts_arr = NULL;
	int i = 0;

	if (tree == NULL)
		return (0);
	bts_arr = binary_tree_array(tree);

	while (bts_arr[i] != 0 && bts_arr[i + 1] != 0)
	{
		if (bts_arr[i] >= bts_arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
/**
 * binary_tree_is_avl - a function that checks
 * if a binary tree is a valid AVL Tree
 *
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (binary_tree_is_bst(tree) == 0)
		return (0);
	return (binary_tree_balance_root(tree));
}
