#include "binary_trees.h"
/**
 * binary_tree_inorder - preorder traversion of a binary tree.
 * @tree: the root of the tree.
 * @func: function to call on each node.
 **/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
