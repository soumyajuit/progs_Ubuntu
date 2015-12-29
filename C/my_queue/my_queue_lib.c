#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include "my_queue_lib.h"

s_q*
simple_q_init(int len)
{   
    s_q *q = NULL;

    q = (s_q*)malloc(sizeof(s_q) + sizeof(void*)*len);

    if (q == NULL) {
        goto out;
    }

    q->arr_len = len;

    memset(q->ptr_arr, 0, sizeof(void*) *q->arr_len);

    q->r_pos = -1;
    q->w_pos = 0;
    q->count = 0;
out:
    return q;
}


void
simple_q_print(s_q *q)
{
    printf("\n q->arr_len %d", q->arr_len);
    printf("\n q->r_pos %d", q->r_pos);
    printf("\n q->w_pos %d", q->w_pos);
}

int
enqueue(s_q *q, void* ele) {
    if (simple_q_full(q)) {
        printf("\n Queue is FULL \n");
        simple_q_print(q);
        return -1;
    }

    return simple_q_enqueue(q, ele);
}

void*
dequeue(s_q *q) {
    if (simple_q_empty(q)) {
        printf("\n Queue is empty \n");
        simple_q_print(q);
        return NULL;
    }

    return simple_q_dequeue(q);
}


