typedef struct queue_s queue_t;

typedef int (*enqueue_fn) (queue_t *q, void* ele);
typedef void* (*dequeue_fn) (queue_t *q);

typedef struct queue_fn_ptr_s {
	enqueue_fn enqueue_fn;
	dequeue_fn dequeue_fn;
}queue_fn_ptr_t;
