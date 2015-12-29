#ifndef _my_queue_lib
#define _my_queue_lib

#define ASSERT  assert

typedef struct s_q_s{
    int r_pos;
    int w_pos;
    int arr_len;
    int count;
    void* ptr_arr[];
} s_q;

static inline int
simple_q_full(s_q *q)
{   
    return (q->count == q->arr_len);
}

static inline int
simple_q_empty(s_q *q)
{   
    return (q->count <= 0);
}

static inline int
simple_q_enqueue(s_q *q, void *ele)
{   
    ASSERT(!simple_q_full(q));
    q->ptr_arr[q->w_pos] = ele;
    q->w_pos = (q->w_pos + 1 ) % q->arr_len;
    q->count++;
    return 0;
}

static inline void*
simple_q_dequeue(s_q *q)
{   
    ASSERT(!simple_q_empty(q));
    q->r_pos = (q->r_pos + 1) % q->arr_len;
    q->count--;
    return q->ptr_arr[q->r_pos];
}

extern s_q* simple_q_init(int len);
extern void simple_q_print(s_q *q);
extern int enqueue(s_q *q, void* ele);
extern void* dequeue(s_q *q);

#endif

