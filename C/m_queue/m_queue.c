#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "m_queue_func.h"

#define MAX_QUEUE_LEN 10

int main(int argc, char *argv[])
{
	int num_ele = 0;
	queue_t *q = NULL;

	scanf("%d", &num_ele);
	q = create_queue(num_ele);



	return 0;
}



queue_t*
create_queue(int num_ele)
{

	queue_t *q = (queue_t*)malloc(sizeof(queue_t) + num_ele);
	
	if (q == NULL) {
		exit(0);
	}

	q->q_fn_ptr = &queue_func_table;

	memset(q->arr, 0, sizeof(void*)*num_ele);
}










