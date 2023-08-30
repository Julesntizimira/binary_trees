# include "binary_trees.h"
# include <stdio.h>
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
/*
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
		if (bts_arr[i] > bts_arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
