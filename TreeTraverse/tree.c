#include <stdlib.h>
#include "tree.h"


/* Init Node of a Tree */
tree_node_t *new_node(int new_data) {
	tree_node_t *node = (tree_node_t *)malloc(sizeof(tree_node_t));

	node->data = new_data;
	node->left = NULL;
	node->right = NULL;

	return node;
}
