#include "binary_trees.h"
/**
 * binary_tree_preorder - preorder traversion of a binary tree.
 * @tree: the root of the tree.
 * @func: function to call on each node.
 **/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
