#include "binary_trees.h"
/**
 * binary_tree_nodes - count the internal nodes of a binary tree.
 * @tree: root of the tree
 *
 * Return: the number of internal nodes.
 **/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);
	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
