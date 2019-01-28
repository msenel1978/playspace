#ifndef tree_h
#define tree_h


struct tree_node {
	int data;
	struct tree_node *left;
	struct tree_node *right;
};

typedef struct tree_node tree_node_t;

tree_node_t *new_node(int new_data); 

#endif