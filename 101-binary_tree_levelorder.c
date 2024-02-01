#include "binary_trees.h"
/**
 * get_levels - get the number of levels in a binary tree
 * @tree: Pointer to the node to measures the height
 *
 * Return: The levels of the tree
 */
int get_levels(const binary_tree_t *tree)
{
	size_t left_level;
	size_t right_level;

	if (!tree)
		return (0);
	left_level = tree->left ? 1 + get_levels(tree->left) : 0;
	right_level = tree->right ? 1 + get_levels(tree->right) : 0;
	return (left_level > right_level ? left_level : right_level);
}

/**
 * travers_level - traverse a binary tree level.
 * @root: root of the tree.
 * @level: level to travers.
 * @func: function to call on the data stored in all nodes in the level.
 **/
void travers_level(const binary_tree_t *root, int level, void (*func)(int))
{
	if (!root)
		return;
	if (level == 0)
	{
		func(root->n);
		return;
	}
	travers_level(root->left, level - 1, func);
	travers_level(root->right, level - 1, func);
}

/**
 * binary_tree_levelorder - level order traversion of a binary tree.
 * @tree: the tree.
 * @func: a fuction to call on the data stored in all nodes in the level.
 **/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int levels = 0, level = 2;

	if (!tree || !func)
		return;
	func(tree->n);
	if (tree->left)
		func(tree->left->n);
	if (tree->right)
		func(tree->right->n);
	levels = get_levels(tree);
	for (; level <= levels; level++)
		travers_level(tree, level, func);
}
