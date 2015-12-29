#include<stdio.h>
#include<stdlib.h>


typedef struct queue_s{
        int head;
        int tail;
        void* arr[];
} queue_t;

int main(int argc, char *argv[])
{

	void** arr = NULL;
	int len = 0;

	len = atoi(argv[1]);

	arr = (void**)malloc(sizeof(void*)*len);

	printf("\n The req_len = %d, and the act size is %lu \n",len, (sizeof(arr)/sizeof(void*)));
	
	return 0;
}

