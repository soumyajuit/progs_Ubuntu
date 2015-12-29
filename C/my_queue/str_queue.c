#include<stdio.h>
#include<stdlib.h>
#include<sys/queue.h>
#include<assert.h>
#include<string.h>
#include "my_queue_lib.h"

static int
queue_driver(int arr[], int len, int queue_len)
{
    void *k  =NULL;
    s_q *q = simple_q_init(queue_len);
    int i =0;

    if (q == NULL) {
        printf("\n Something went wrong \n");
        return -1;
    }


    while(enqueue(q, &arr[i]) >= 0) {
        printf("\n %d %d", arr[i], i);
        i++;
        if (i >= len) {
            printf("\n exit here \n");
            break;
        }
    }

    simple_q_print(q);

    while((k = dequeue(q))) {
        printf("\n %d\n", *((int*)k));
    }

    return 0;
}


int main(int argc, char *argv[])
{
    int i = 0;
    int count = 0;
    int arr[100] = {0};

    scanf("%d", &count);

    while(scanf("%d", &arr[i]) != EOF) {
        if (count <= i) {
            break;
        }
        printf("\n %d %d", arr[i], i);
        i++;
    }

    printf("\n =========== \n");
    
    queue_driver(arr, count, 10);

    return 0;
}


