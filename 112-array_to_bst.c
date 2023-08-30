# include "binary_trees.h"
/**
 * array_to_bst - a function that
 * builds a Binary Search Tree
 *
 *
 * @array: a pointer to the first element of
 * the array to be converted
 *
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the
 * created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	int value;
	size_t i = 0;


	if (array == NULL || size <= 0)
		return (NULL);

	while (i < size)
	{
		value = array[i];
		if (bst_insert(&tree, value) == NULL)
			return (NULL);
		i++;
	}
	return (tree);
}
