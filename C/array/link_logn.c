#include<stdio.h>
#include<stdlib.h>


typedef struct link_s{
	int val;
	struct link_s *next;
} link_t;


static link_t*
create_link(int val)
{
	link_t *_t = NULL;
	_t = (link_t*)malloc(sizeof(link_t));

	_t->val = val;
	_t->next = NULL;

	return _t;
}


static int
add_link(link_t *head, link_t *new_node)
{

	if (new_node == NULL) {
		return -1;
	}

	if (new_node->val > head->val) {
		return (head->next, new_node);
