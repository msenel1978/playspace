#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "tree.h"


/* Print the content of the array, that stores visited paths */
void print_visited_path(int path[], int pathlen) {
	int i;

	for (i = 0; i < pathlen; i++)
		printf("%d ", path[i]);

	printf("\n");

}

/* Via recursion, visit all nodes	*/
/* Store the values to print later	*/ 	
void print_paths(tree_node_t *node, int path[], int len) {

	if (node == NULL)
		return;

	/* Store nodes until the leaves are reached */
	path[len] = node->data;
	len++;

	if (node->left==NULL && node->right==NULL)
		print_visited_path(path, len);
	else {
		print_paths(node->left, path, len);
		print_paths(node->right, path, len);
	}
}

/* Via recursion, visit all nodes	*/
/* Store the values to print later	*/ 	
void print_paths_stack(tree_node_t *node, new_stack_t *path) {

	if (node == NULL)
		return;

	/* Store nodes until the leaves are reached */
	push_stack(node->data, path);

	if (node->left==NULL && node->right==NULL) {
		/* TODO: Do I need to pop? */
		print_stack(path);
	}
	else {
		print_paths_stack(node->left, path);
		print_paths_stack(node->right, path);
	}
}



int main()
{
	int path[1000];
	new_stack_t *path_stack = malloc(sizeof(new_stack_t));

	tree_node_t *root = new_node(5);

	root->left = new_node(8);
	root->right = new_node (-1);
	root->left->left = new_node(5);
	root->left->right = new_node(3);
	root->right->right = new_node (2);

	printf("\n");

	print_paths(root, path, 0);
	print_paths_stack(root, path_stack);
	printf("\n");


}