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
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: root of the tree.
 *
 * Return: the balance.
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	int h_l, h_r;

	if (!tree)
		return (0);
	h_l = tree->left ? 1 + t_height(tree->left) : 0;
	h_r = tree->right ? 1 + t_height(tree->right) : 0;
	return (h_l - h_r);
}
