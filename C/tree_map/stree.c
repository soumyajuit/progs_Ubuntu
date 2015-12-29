#include<stdio.h>
#include"stree.h"



int main(int argc, char *argv[])
{

}

bin_tree_node_t*
create_bin_tree_node(int val)
{
	bin_tree_node_t *node = NULL;

	node = (bin_tree_node_t*)malloc(sizeof(bin_tree_node_t));

	node->tree_link = create_node();
	
	if (node->tree_link == NULL) {
		MEM_FAILURE();
		free(node);
		exit();
	}

	node->data = int;
	//assign_color();
}


int
bin_tree_add(bin_tree_t *bin_tree, int value)
{
	bin_tree_node *node;

	node = create_bin_tree_node(value);
	if (bin_tree == NULL) {
		goto error;
	}

	if (bin_tree->root == NULL) {
		bin_tree->root = create_node(new_data);
	}

	bin_tree_add_node(bin_tree->root, create_node(new_data));
}

int
bin_tree_add_node(node_t* parent, node_t* new_node)
{

}	
