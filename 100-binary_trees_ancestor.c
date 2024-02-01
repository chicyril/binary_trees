#include "binary_trees.h"
/**
 * depth - calculater the depth of a node.
 * @tree: the node whose depth to calculate.
 *
 * Return: depth
 **/
int depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);
	while (tree->parent)
	{
		tree = tree->parent;
		depth++;
	}
	return (depth);
}
/**
 * binary_trees_ancestor - find the lowest common ancestor of 2 nodes.
 * @first: first node
 * @second: second node
 *
 * Return: the lowest common ancestor.
 **/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *deep = first, *deepish = second;
	int deep_depth, deepish_depth, diff = 0;

	if (!first || !second)
		return (NULL);
	if (!first->parent || !second->parent)
		return (!first->parent ? (binary_tree_t *)first
				: (binary_tree_t *)second);
	deep_depth = depth(first);
	deepish_depth = depth(second);
	if (deep_depth != deepish_depth)
	{
		if (deep_depth < deepish_depth)
		{
			deep = second;
			deepish = first;
			diff = deepish_depth;
			deepish_depth = deep_depth;
			deep_depth = diff;
		}
		diff = deep_depth - deepish_depth;
		while (diff)
		{
			deep = deep->parent;
			diff--;
		}
	}
	while (deep->parent != deepish->parent)
	{
		deep = deep->parent;
		deepish = deepish->parent;
	}
	if (deep == deepish)
		return ((binary_tree_t *)deep);
	return (deep->parent);
}
