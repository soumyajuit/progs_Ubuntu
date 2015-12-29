#include<stdio.h>
#include<stdlib.h>
#include "m_queue_func.h"

#define MAX(a,b) ((a > b) ? a : b)

typedef struct node_s{
	int val;
	struct node_s *left;
	struct node_s *right;
	struct node_s *p;
	int height;
	int bal_factor;
}node;

typedef struct tree_s {
	node *root;
} tree;

#define HEIGHT(node)	((node == NULL) ? -1 : node->height)
#define MAX_QUEUE_LEN	50

tree* create_tree(node *root);

node* create_node(int val);
node* add_node(node *root, int val);
node* rotate_right(node* y, tree* t);
node* rotate_left(node* y, tree* t);
void print_tree(tree *t);
void print_inorder(node *root);
void print_preorder(node *root);


int main(int argc, char *argv[])
{
	node *root = NULL;
	tree *t = NULL;
	int val = 0;

	scanf("%d", &val);

	do{
		root = add_node(root, val);
		scanf("%d", &val);
	} while(val != -1);

	t = create_tree(root);

	printf("\n root = %p \n", t->root);
	print_tree(t);
	printf("\n after rotation \n");
	rotate_right(t->root->left, t);
	printf("\n root = %p \n", t->root);
	print_tree(t);
	//printf("\n diameter is %d", get_diameter(root));
}


tree*
create_tree(node *root)
{

	tree *t =NULL;

	t = (tree*)malloc(sizeof(tree));
	if (t == NULL) {
		return NULL;
	}

	t->root = root;
}

node*
create_node(int val)
{
	node* t_node = NULL;
	t_node = (node*) malloc(sizeof(node));

	if (t_node == NULL) {
		return NULL;
	}

	t_node->left = NULL;
	t_node->right = NULL;
	t_node->p = NULL;
	t_node->height = 0;
	t_node->bal_factor = 0; 
	t_node->val = val;

	return t_node;
}

node*
add_node(node *root, int val)
{

	if (root == NULL) {
		return create_node(val);
	}
		
	if (root->val < val) {
		root->right  = add_node(root->right, val);
		root->right->p = root;
		root->height = 1 + MAX(HEIGHT(root->right), HEIGHT(root->left));
		root->bal_factor = HEIGHT(root->left) - HEIGHT(root->right);
	} else if (root->val > val) {
		root->left  = add_node(root->left, val);
		root->left->p = root;
		root->height = 1 + MAX(HEIGHT(root->right), HEIGHT(root->left));
		root->bal_factor = HEIGHT(root->left) - HEIGHT(root->right);
	}

	return root;
}


node*
rotate_right(node* y, tree* t)
{

	node *p;
	p = y->p;

	if (p == NULL) {
		printf("\n Wrong tree rotation \n");
		exit(255);
	}

	if (p != t->root && p == p->p->left) {
		p->p->left = y;
	} else if (p != t->root && p == p->p->right) {
		p->p->right = y;
	} else if (p == t->root) {
		t->root = y;
	}

	p->p = y;
	y->p = p->p;

	p->left = y->right;
	y->right->p = p;
	
	y->right = p;

	p->height = 1 + MAX(HEIGHT(p->left), HEIGHT(p->right));
	y->height = 1 + MAX(HEIGHT(y->left), HEIGHT(y->right));
	
	return y;
}

node*
rotate_left(node* y, tree* t)
{

	node *p;
	p = y->p;

	if (p == NULL) {
		printf("\n Wrong tree rotation \n");
		exit(255);
	}

	if (p != t->root && p == p->p->left) {
		p->p->left = y;
	} else if (p != t->root && p == p->p->right) {
		p->p->right = y;
	} else if (p == t->root) {
		t->root = y;
	}

	p->p = y;
	y->p = p->p;

	p->right = y->left;
	y->left->p = p;
	
	y->left = p;

	p->height = 1 + MAX(HEIGHT(p->left), HEIGHT(p->right));
	y->height = 1 + MAX(HEIGHT(y->left), HEIGHT(y->right));

	p->bal_factor = HEIGHT(p->left) - HEIGHT(p->right);
	y->bal_factor = HEIGHT(y->left) - HEIGHT(y->right);

	return y;
}

void
print_tree(tree *t)
{
	print_preorder(t->root);

}

void
print_inorder(node *root)
{
	if (root == NULL) {
		return;
	}

	print_inorder(root->left);
	printf("\n %d --> %d --> %d", root->val, root->height, root->bal_factor);
	print_inorder(root->right);

	return;
}


void
print_preorder(node *root)
{
	if (root == NULL) {
		return;
	}

	printf("\n %d --> %d --> %d", root->val, root->height, root->bal_factor);
	print_preorder(root->left);
	print_preorder(root->right);

	return;
}

int
get_diameter(node *root)
{
	int dim = 0;

	find_dim(root, &dim);
	return dim;
}


int
find_dim(node *root, int *dim)
{
	int l = 0;
	int r = 0;
	int l_dim = 0;
	int r_dim = 0;

	if (root->left == NULL && root->right  == NULL) {
		return 1;
	}

	if (root->left != NULL) {
		l = find_dim(root->left, dim);
		l_dim = *dim;
	}


	if (root->right != NULL) {
		r = find_dim(root->right, dim);
		r_dim = *dim;
	}


	//*dim = MAX(*dim,MAX(MAX(l_dim,r_dim),(1+l+r)));
	*dim = MAX(*dim,(1+l+r));

	return (1+MAX(l,r));
}



void
print_tree_level_wise(tree *t)
{
	queue_t *q = NULL;

	q = (queue_t*)malloc(sizeof(queue_t) + MAX_QUEUE_LEN);
}
