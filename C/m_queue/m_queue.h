#include "m_queue_fn.h"

typedef struct queue_s{
	int head;
	int tail;
	int len;
	queue_fn_ptr_t *q_fn_ptr;
	void* arr[];
} queue_t;
