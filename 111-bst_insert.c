# include "binary_trees.h"
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
