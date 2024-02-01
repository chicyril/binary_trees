#include "binary_trees.h"
/**
 * node_count - calculate the total number of nodes in a tree.
 * @tree: root of tree to count.
 *
 * Return: the number of nodes.
 **/
int node_count(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + node_count(tree->left) + node_count(tree->right));
}

/**
 * iscomplete - helper function to chechk if a binary tree is complete.
 * @root: current node.
 * @index: current index.
 * @nodes: total number of nodes in the tree.
 *
 * Return: 1 if complete, else 0.
 **/
int iscomplete(const binary_tree_t *root, int index, int nodes)
{
	if (!root)
		return (1);
	if (index >= nodes)
		return (0);
	return (iscomplete(root->left, 2 * index + 1, nodes)
			&& iscomplete(root->right, 2 * index + 2, nodes));
}
/**
 * binary_tree_is_complete - check if a binary tree is complete.
 * @tree: the tree to check
 *
 * Return: 1 if complete, else 0.
 **/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int index = 0, nodes = node_count(tree);

	if (!tree)
		return (0);
	return (iscomplete(tree, index, nodes));
}
