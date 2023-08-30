# include "binary_trees.h"
# include <stdio.h>
bst_t *successor_serch(bst_t *tree)
{
	bst_t *temp = tree;

	temp = temp->right;
	
	while (temp->left != NULL)
		temp = temp->left;
	temp->parent->left = NULL;
	temp->parent = tree->parent;

	temp->left = tree->left;
	temp->right = tree->right;

	if (temp->parent != NULL)
	{
		if (temp->n > temp->parent->n)
			temp->parent->right = temp;
		else
			temp->parent->left = temp;
	}
	return (temp);

}

/**
 * bst_remove - a function that removes a
 * node from a Binary Search Tree
 *
 * @root: is a pointer to the root node of the tree
 *
 * @value is the value to remove in the tree
 *
 * Once located, the node containing a value equals to value must be removed and freed
 * If the node to be deleted has two children,
 * it must be replaced with its first in-order successor (not predecessor)
 * 
 * Return:  a pointer to the new root node of the tree
 * after removing the desired value
 */ 

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp = NULL, *succ = NULL, *curr = NULL;
	
	if (root == NULL)
		return (NULL);
	tmp = root;
	while (tmp != NULL)
        {
		if (tmp->n == value)
			break;

                if (value < tmp->n)
			tmp = tmp->left;
                else if (value > tmp->n)
			tmp = tmp->right;
	}
	if (tmp == NULL)
		return (NULL);
	if (tmp->left == NULL && tmp->right == NULL)
		free(tmp);
	else if ((tmp->left != NULL && tmp->right == NULL) || (tmp->left == NULL && tmp->right != NULL))
        {
		if (tmp->left)
			curr = tmp->left;
		else if (tmp->right)
			curr = tmp->right;
		
		if (curr->n > tmp->parent->n)
			tmp->parent->right = curr;
		else
			tmp->parent->left = curr;
		curr->parent = tmp->parent;
                free(tmp);
        }
	else if (tmp->left != NULL || tmp->right != NULL)
	{
		succ = successor_serch(tmp);
		if (succ->parent == NULL)
			root = succ;
		free(tmp);
	}
	return root;
}
