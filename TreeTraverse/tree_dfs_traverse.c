#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "tree.h"


/* Print the content of the array, that stores visited paths */
void print_visited_path(int path[], int pathlen) {
	int i;

	for (i = 0; i < pathlen; i++)
		printf("%d\t", path[i]);

	printf("\n");

}

/* Via recursion, visit all nodes	*/
/* Store the values to print later	*/ 	
void print_paths(tree_node_t *node, int path[], int len) {

	/* Tree empty */
	if (!node) {
		return;
	}

	/* Store nodes until the leaves are reached */
	path[len] = node->data;
	len++;

	if ((node->left == NULL) && (node->right == NULL))
		print_visited_path(path, len);
	else {
		print_paths(node->left, path, len);
		print_paths(node->right, path, len);
	}
}

/* Via recursion, visit all nodes			*/
/* Store the values to print later			*/
/* This implementation is based on stacks	*/
void print_paths_queue(tree_node_t *node, queue_t *path, int len) {
	int i;
	q_element_t *print_element;

	/* Tree empty */
	if (!node) {
		return;
	}

	/* Store nodes until the leaves are reached */
	if (len < path->cnt)
		replace_element_queue(path, len, node->data);
	else
		enqueue(node->data, path);
	len++;

	if ((node->left == NULL) && (node->right == NULL)) {
		print_element = path->front;
		for (i = 0; i < len; i++) {
			printf("%d\t", print_element->d);
			print_element = print_element->next;		
		}
		printf("\n");
	}
	else {
		print_paths_queue(node->left, path, len);
		print_paths_queue(node->right, path, len);
	}
}



int main()
{
	int path[1000];
	queue_t *path_queue = malloc(sizeof(queue_t));

	tree_node_t *root = new_node(5);

	root->left = new_node(8);
	root->right = new_node (-1);
	root->left->left = new_node(5);
	root->left->right = new_node(3);
	root->right->right = new_node (2);

	printf("\nArray Implementation\n");
	print_paths(root, path, 0);

	/* Queue Implementation */
	printf("\nQueue Implementation\n");
	initialize_queue(path_queue);
	print_paths_queue(root, path_queue, 0);
	printf("\n");


}