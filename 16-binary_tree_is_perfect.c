#include "binary_trees.h"
/**
 * t_height - Measures the height of a binary tree
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
size_t t_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (!tree)
		return (0);
	height_l = tree->left ? 1 + t_height(tree->left) : 0;
	height_r = tree->right ? 1 + t_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: root of the tree to check.
 *
 * Return: 1 if perfect else 0.
 **/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int h_l, h_r;

	if (!tree || ((tree->left || tree->right) && !(tree->left && tree->right)))
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (!binary_tree_is_perfect(tree->left) ||
			!binary_tree_is_perfect(tree->right))
		return (0);
	h_l = tree->left ? 1 + t_height(tree->left) : 0;
	h_r = tree->right ? 1 + t_height(tree->right) : 0;
	if (h_l != h_r)
		return (0);
	return (1);
}
