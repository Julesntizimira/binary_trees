#include "binary_trees.h"

/**
 * sorted_array_to_avl_helper - recursive helper function to construct AVL tree
 *
 * @array: input sorted array
 * @start: start index of the current range
 * @end: end index of the current range
 * @parent: parent node of the current node
 *
 * Return: root node of the constructed AVL tree
 */
avl_t *sorted_array_to_avl_helper(int *array, size_t start,
		size_t end, avl_t *parent)
{
	if (end - start > 1)
	{
		size_t mid = start + (end - start) / 2;
		avl_t *node = binary_tree_node(parent, array[mid]);

		if (node == NULL)
			return (NULL);
		node->left = sorted_array_to_avl_helper(array, start, mid, node);
		node->right = sorted_array_to_avl_helper(array, mid, end, node);
		return (node);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - constructs an AVL tree from a sorted array
 *
 * @array: input sorted array
 * @size: size of the array
 *
 * Return: root node of the constructed AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (sorted_array_to_avl_helper(array, -1, size, NULL));
}
