#include "binary_trees.h"
/**
 * binary_tree_postorder - preorder traversion of a binary tree.
 * @tree: the root of the tree.
 * @func: function to call on each node.
 **/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
