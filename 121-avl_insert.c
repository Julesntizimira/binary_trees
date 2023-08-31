# include "binary_trees.h"
# include <stdio.h>
/**
 * bst_insert - a function that inserts a
 * value in a Binary Search Tree
 *
 * @tree: a double pointer to the root node of
 * the BST to insert the value
 *
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 * If the address stored in tree is NULL, the created node
 * must become the root node.
 * If the value is already present in the tree, it must be ignored
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *newnode = NULL, *tmp = *tree;

	newnode = malloc(sizeof(bst_t));
	if (newnode == NULL)
		return (NULL);
	newnode->parent = newnode->left = newnode->right = NULL;
	newnode->n = value;
	if (*tree == NULL)
		*tree = newnode;
	while (tmp != NULL)
	{
		if (value < tmp->n)
		{
			if (tmp->left == NULL)
			{
				newnode->parent = tmp;
				tmp->left = newnode;
				break;
			}
			tmp = tmp->left;
		}
		else if (value > tmp->n)
		{
			if (tmp->right == NULL)
			{
				newnode->parent = tmp;
				tmp->right = newnode;
				break;
			}
			tmp = tmp->right;
		}
		else if (value == tmp->n)
		{
			free(newnode);
			return (NULL);
		}
	}
	return (newnode);
}
/**
 * tree_balancer - a function that measures
 * the balance factor of a binary tree from bottom-top
 * post order traversal
 * check if the whole tree is balanced
 *
 * @tree: a pointer to the root node of the
 * tree to measure the balance factor
 *
 * Return: the unbalanced node or NULL
 */
bst_t *tree_balancer(binary_tree_t *tree)
{
	int b_factor;
	binary_tree_t *tmp = NULL;

	if (tree == NULL)
		return (NULL);
	if (tree->left != NULL)
	{
		tmp = tree_balancer(tree->left);
		if (tmp != NULL)
			return (tmp);
	}
	if (tree->right != NULL)
	{
		tmp = tree_balancer(tree->right);
		if (tmp != NULL)
			return (tmp);
	}
	b_factor = binary_tree_balance(tree);

	if (b_factor > 1 || b_factor < -1)
	{
		tmp = tree;
		return (tmp);
	}
	return (NULL);
}
/**
 * avl_insert - a function that inserts a value in an AVL Tree
 *
 * @tree: a double pointer to the root node of the
 * AVL tree for inserting the value
 *
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 *
 * If the address stored in tree is NULL,
 *
 * the created node must become the root node.
 * The resulting tree after insertion, must be a balanced AVL Tree
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int b_factor;
	avl_t *tmp = NULL, *node = NULL;

	tmp = bst_insert(tree, value);
	if (tmp == NULL)
		return (NULL);
	node = tree_balancer(*tree);
	if (node != NULL)
	{
		b_factor = binary_tree_balance(node);
		if (b_factor < -1)
		{
			if (binary_tree_balance(node->right) > 0)
				binary_tree_rotate_right(node->right);
			binary_tree_rotate_left(node);
		}
		else
		{
			if (binary_tree_balance(node->left) < 0)
				binary_tree_rotate_left(node->left);
			binary_tree_rotate_right(node);
		}
	}
	return (tmp);
}
