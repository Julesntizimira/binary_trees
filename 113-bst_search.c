# include "binary_trees.h"
/**
 * bst_search -  a function that searches
 * for a value in a Binary Search Tree
 *
 * @tree: a pointer to the root node of the BST to search
 *
 * @value: the value to search in the tree
 *
 * Return: a pointer to the node containing a value equals to value
 * If tree is NULL or
 * if nothing is found, your function must return NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *tmp = (bst_t *)tree;

	if (tree == NULL)
		return (NULL);

	if (tmp->n == value)
		return (tmp);

	while (tmp != NULL)
	{
		if (value < tmp->n)
		{
			if (tmp->left != NULL && tmp->left->n == value)
				return (tmp->left);
			tmp = tmp->left;
		}
		else if (value > tmp->n)
		{
			if (tmp->right != NULL && tmp->right->n == value)
				return (tmp->right);
			tmp = tmp->right;
		}
	}
	return (NULL);
}
