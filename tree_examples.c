#include <stdio.h>
#include <stdlib.h>

struct tree_node {
	int data;
	struct tree_node *left;
	struct tree_node *right;
};

typedef struct tree_node tree_node_t;

tree_node_t *new_node(int new_data) {
	tree_node_t *node = (tree_node_t *)malloc(sizeof(tree_node_t));

	node->data = new_data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void print_visited_path(int path[], int pathlen) {
	int i;

	for (i = 0; i < pathlen; i++)
		printf("%d ", path[i]);

	printf("\n");

}

void print_paths(tree_node_t *node, int path[], int len) {

	if (node == NULL)
		return;

	path[len] = node->data;
	len++;

	if (node->left==NULL && node->right==NULL)
		print_visited_path(path, len);
	else {
		print_paths(node->left, path, len);
		print_paths(node->right, path, len);
	}
}

void print_tree(tree_node_t *node) {

	if (node == NULL) 
          return; 
  
     /* first print data of node */
     printf("%d ", node->data);

     /* then recur on left subtree */
     print_tree(node->left);   
  
     /* now recur on right subtree */
     print_tree(node->right);   
}

int main()
{
	int path[1000];

	tree_node_t *root = new_node(5);

	root->left = new_node(8);
	root->right = new_node (-1);
	root->left->left = new_node(5);
	root->left->right = new_node(3);
	root->right->right = new_node (2);

	print_tree(root);
	printf("\n\n");

	print_paths(root, path, 0);

}