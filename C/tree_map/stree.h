#include"stree_lib.h"

typedef struct node_s{
	struct node_s *left;
	struct node_s *right;
}node_t;

static inline node_t*
create_node(void)
{
	node_t *tmp = NULL;
	tmp = (node_t*)malloc(sizeof(node_t));

	if (tmp == NULL) {
		MEM_FAILURE();
		return NULL;
	}

	tmp->left = tmp->right = NULL;
	return tmp;
}
