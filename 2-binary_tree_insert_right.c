#include "binary_trees.h"
/**
 * binary_tree_insert_right - insert a node as right child of another node.
 * @parent: direct predecessor of the new node.
 * @value: the data to store in the new node.
 *
 * Return: a pointer to the created node.
 **/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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
	if (parent->right)
	{
		parent->right->parent = new_node;
		new_node->right = parent->right;
	}
	parent->right = new_node;
	new_node->parent = parent;
	return (new_node);
}
