#include<stdio.h>
#include<stdlib.h>

#define RED 1
#define BLACK 2

typedef struct node_s{
	int val;
	int color;
	struct node_s *left;
	struct node_s *right;
	struct node_s *p;
}node_t;

typedef struct tree_s {
	node_t *root;
}tree_t;


tree_t* create_tree(void);

node_t* create_node(node_t* p, int val, int color);
node_t* insert_in_tree(node_t *root, int val);
node_t* add_node(node_t *parent, int val);
node_t* rotate_left(tree_t *tree, node_t* node);
node_t* rotate_right(tree_t *tree, node_t* node);

void delete_node(node_t *node);
void display_inorder(node_t* node);

int main(int argc, char *argv[])
{
	tree_t *tree = NULL;
	int val;	

	tree = create_tree();
	do{
		scanf("%d", &val);
		if (val == -1) {
			break;
		}

		if (tree->root == NULL) {
			tree->root = insert_in_tree(tree->root, val);	
		} else {
			(void)insert_in_tree(tree->root, val);
		}

	}while(1);

	//rotate_left(tree, tree->root);
	rotate_right(tree, tree->root);
	display_inorder(tree->root);
	printf("\n Tree root val = %d color = %d \n", tree->root->val, tree->root->color);

	return 0;
}
	

tree_t*
create_tree(void)
{

	tree_t *t_tree = NULL;

	t_tree = (tree_t*)malloc(sizeof(tree_t));

	if (t_tree == NULL) {
		printf("\n Mem failure \n");
	}

	t_tree->root = NULL;
	return t_tree;
}

node_t*
create_node(node_t* p, int val, int color)
{
	node_t *tmp = NULL;
	tmp = (node_t*)malloc(sizeof(node_t));

	if (tmp == NULL) {
		return NULL;
	}

	tmp->left = tmp->right = NULL;
	tmp->val = val; tmp->color = color;
	tmp->p = p;
	return tmp;
}

void
delete_node(node_t *node)
{
	free(node);
}

node_t*
insert_in_tree(node_t *root, int val)
{
	node_t *node = NULL;
	if (root == NULL) {
		node = create_node(NULL, val, BLACK);
		return node;
	}

	return add_node(root, val);
}

node_t*
add_node(node_t *parent, int val)
{

	if (parent  == NULL) {
		printf("\n Can't send a NULL parent \n");
		exit(0);
	}

	if (parent->val > val) {
		if (parent->left == NULL) {
			parent->left = create_node(parent, val, RED);
		} else {
			add_node(parent->left, val);
		}
	} else if (parent->val < val) {
		if (parent->right == NULL) {
			parent->right = create_node(parent, val, RED);
		} else {
			add_node(parent->right, val);
		}
	} else {
		printf("\n duplicate values \n");
		exit(0);
	}

	return NULL;
}


void
display_inorder(node_t* node)
{
	if (node == NULL) {
		return;
	}

	display_inorder(node->left);
	display_inorder(node->right);

	printf("\n val = %d, color = %d \n", node->val, node->color);
	return;
}

node_t*
rotate_left(tree_t *tree, node_t* node)
{

	node_t *t_node = NULL;

	t_node = node->right;
	node->right = t_node->left;
	t_node->left = node;
	
	t_node->p = node->p;

	if (node->p != NULL) {
		if (node->p->val > node->val) {
			node->p->left = t_node;
		} else {
			node->p->right = t_node;
		}
	} else {
		tree->root = t_node;
	}

	node->p = t_node;

	return t_node;
}


node_t*
rotate_right(tree_t *tree, node_t* node)
{

	node_t *t_node = NULL;

	t_node = node->left;
	node->left = t_node->right;
	t_node->right = node;
	
	t_node->p = node->p;

	if (node->p != NULL) {
		if (node->p->val > node->val) {
			node->p->left = t_node;
		} else {
			node->p->right = t_node;
		}
	} else {
		tree->root = t_node;
	}

	node->p = t_node;

	return t_node;
}


node_t*
find_node(node_t* node, int val)
{

	return ((node != NULL) ? NULL : ((node->val > val) ? 
					find_node(node->left, val) : 
					find_node(node->right, val)));

}


int
del_node(tree_t *tree, int val)
{
	node_t *node = NULL;

	node = find_node(tree->root, val);
	if (node == NULL) {
		return -1;
	}

	delete_tree_node1(tree, node);
}


delete_tree_node1(tree_t *tree, node_t *node)
{
	node_t *new_node = NULL;
	
	if (node->right != NULL) {
		new_node = get_ext_right(node);
	} else if (node->left != NULL) {
		new_node = get_ext_left(node);
	} else {
		new_node = NULL;
		delete_node(node);
	}

	if (new_node->p->left == new_node) {
		new_node->p->left = NULL;
	} else {
		new_node->p->right = NULL;
	} 

	new_node->p = node->p;
	new_node->left = node->left;
	new_node->right = node->right;

	node->left->p = node->right->p = new_node;

	if (node->p->left == node) {
		node->p->left = new_node;
	} else {
		node->p->right = new_node;
	}




int
delete_tree_node2(tree_t *tree, node_t *del_node, node_t *parent_node)
{

	return -1;
}

node_t*
get_ext_right(node_t *node)
{
	if (node->right == NULL) {
		return node;
	}

	return get_ext_right(node->right);
}

node_t*
get_ext_left(node_t *node)
{
	if (node->left == NULL) {
		return node;
	}

	return get_ext_left(node->left);
}







