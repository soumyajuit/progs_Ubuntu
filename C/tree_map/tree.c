#include<stdio.h>
#include<stdlib.h>

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

tree* create_tree(node *root);

node* create_node(int val);
node* add_node(node *root, int val);
node* rotate_right(node* y, tree* t);
node* rotate_left(node* y, tree* t);
node* find_some(node *root, int val);
node* is_some_present(tree *t, int val);
void print_tree(tree *t);
void print_inorder(node *root);
void print_preorder(node *root);


int main(int argc, char *argv[])
{
	node *root = NULL;
	tree *t = NULL;
	int val = 0;
	node *t_node = NULL;

	scanf("%d", &val);

	do{
		root = add_node(root, val);
		scanf("%d", &val);
	} while(val != -1);

	t = create_tree(root);

	printf("\n root = %p \n", t->root);
	print_tree(t);
	printf("\n after rotation \n");
	//rotate_right(t->root->left, t);
	//printf("\n root = %p \n", t->root);
	//print_tree(t);
	//printf("\n diameter is %d", get_diameter(root));
	printf("\n Enter the value to find:");
	scanf("%d", &val);
	printf("\n The element which found is %d", is_some_present(t, val)->val); 
	printf("\n Enter the value and the to be replaced:");
	scanf("%d %d", &val, &new_val);
	
	t_node = find_and_replace(root, val, new_val);

	if (t_node != NULL) {
		printf("\n The new value is %d", t_node->val);
	} else {
		printf("\n The val is not present \n");
	}
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

node*
is_some_present(tree *t, int val)
{

	node* ret = 0;

	ret  = find_some(t->root, val);
	return ret;

}


node*
find_and_replace(node *node, int old_val, int new_val)
{
	if (node == NULL) {
		return NULL;
	}

	if (node->val > old_val) {
		return find_and_replace(node, old_val, new_val);
	} else if (node->val < old_val) {
		return find_and_replace(node, old_val, new_val);
	} else {
		node->val = new_val;
	}

	return node;
}



node*
find_some(node *root, int val)
{

	node* ret = NULL;
	node* ret_l = NULL;
	node* ret_r = NULL;
	node* ret_cur = NULL;

	if (root == NULL) {
		return NULL ;
	}

	if ((val - root->val == 0)) {
		ret_cur = root;
	}

	ret_l = find_some(root->left, val - root->val);
	ret_r = find_some(root->right, val - root->val);

	if (ret_cur != NULL) {
		ret = ret_cur;
	} else if (ret_r != NULL) {
		ret = ret_l;
	} else if (ret_l != NULL) {
		ret = ret_r;
	} else {
		ret = NULL;
	}

}



