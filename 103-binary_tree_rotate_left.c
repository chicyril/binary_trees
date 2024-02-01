#include "binary_trees.h"
/**
 * binary_tree_rotate_left - perform a left rotation on a node.
 * @tree: the node of the binary tree.
 *
 * Return: pointer to the new node.
 **/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (!tree || !tree->right)
		return (NULL);
	tree->right->parent = tree->parent;
	if (tree->parent)
		tree->parent->left = tree->right;
	tree->parent = tree->right;
	tree->right = tree->right->left;
	tree->parent->left = tree;
	if (tree->right)
		tree->right->parent = tree;
	return (tree->parent);
}
