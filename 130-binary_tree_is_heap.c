# include "binary_trees.h"
# include <stdio.h>
int *is_heap_helper(const binary_tree_t *tree)
{
        static size_t count = 1, i = 1, idx = 1, flag = 1;
	static int array[1024] = {0};

        if (tree == NULL)
		return (NULL);
        if (i == count)
        {
		array[idx - 1] = tree->n;
		idx++;
                flag = 2;
        }
	if (count == i - 1)
	{
		if (tree->left == NULL)
		{
			array[idx - 1] = -99;
			idx++;
		}
		   if (tree->right == NULL)
                {
                        array[idx - 1] = -99;
                        idx++;
                }
	}
        if (tree->left != NULL)
        {
                count++;
		is_heap_helper(tree->left);
                count--;
        }	
        if (tree->right != NULL)
        {
                count++;
		is_heap_helper(tree->right);
                count--;
        }
        if (count == 1)
        {
                if (flag == 1)
		{
			i = 1;
			array[idx - 7] = 0;
			idx = 1;
			return (array);
		}
                i++;
                flag = 1;
		is_heap_helper(tree);
        }
	return array;
}
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
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int *array = NULL;
	int i = 0, flag = 0;

	if (tree == NULL)
		return (0);
	
	if (is_max_helper(tree) == 0)
		return (0);
	
	array = is_heap_helper(tree);

	while (array[i] != 0)
	{
		if (flag == 1 && array[i] != -99)
			return (0);
		if (array[i] == -99)
			flag = 1;
		i++;
	}
	return (1);
}
