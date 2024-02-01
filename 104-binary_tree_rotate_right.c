#include "binary_trees.h"
/**
 * binary_tree_rotate_right - perform a right rotation on a node.
 * @tree: the node of the binary tree.
 *
 * Return: pointer to the new node.
 **/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (!tree || !tree->left)
		return (NULL);
	tree->left->parent = tree->parent;
	if (tree->parent)
		tree->parent->right = tree->left;
	tree->parent = tree->left;
	tree->left = tree->left->right;
	tree->parent->right = tree;
	if (tree->left)
		tree->left->parent = tree;
	return (tree->parent);
}
