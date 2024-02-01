#include "binary_trees.h"
/**
 * binary_tree_sibling - find the sibling of a binary tree node.
 * @node: the no to find its sibling.
 *
 * Return: pointer to the sibling.
 **/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node->parent->left != node)
		return (node->parent->left);
	return (node->parent->right);
}
