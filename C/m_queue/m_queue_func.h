#include "m_queue_header.h"
#include "m_queue.h"

static inline int 
queue_sanity(queue_t *q) 
{
	if (q->arr == NULL) {
		return -1;
	}

	if (q->len == 0) {
		return -1;
	}

	return 0;
}

static inline int 
enqueue(queue_t *q, void *ele)
{
	if (queue_sanity(q)) {
		return -1;
	}

	if (q->head == q->tail) {
		return -1;
	}	

	q->arr[q->tail] = ele;
	q->tail = ((q->tail++) % q->len);
}

static inline void* 
dequeue(queue_t *q) 
{

	void* ele = NULL;

	if(queue_sanity(q)) {
		return NULL;
	}

	if (q->head == q->tail) {
		return NULL;
	}

	ele = q->arr[q->head];
	
	q->head = (q->head++) % q->len;

	return ele;
}


queue_fn_ptr_t queue_func_table = {enqueue,
				  dequeue};



