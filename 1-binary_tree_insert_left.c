#include "binary_trees.h"
/**
 * binary_tree_insert_left - insert a node as left child of another node.
 * @parent: direct predecessor of the new node.
 * @value: the data to store in the new node.
 *
 * Return: a pointer to the created node.
 **/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (!parent)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	if (parent->left)
	{
		parent->left->parent = new_node;
		new_node->left = parent->left;
	}
	parent->left = new_node;
	new_node->parent = parent;
	return (new_node);
}
