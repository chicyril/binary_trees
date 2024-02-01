#include "binary_trees.h"
/**
 * binary_tree_uncle - find the uncle of a binary tree node.
 * @node: the node.
 *
 * Return: the address of the uncle.
 **/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	if (node->parent != node->parent->parent->left)
		return (node->parent->parent->left);
	return (node->parent->parent->right);
}
