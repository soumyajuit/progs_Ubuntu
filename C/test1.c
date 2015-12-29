#include<stdio.h>
#include<stdlib.h>

#define MAX_TYP 100

/*static long mytypes[MAX_TYP] = {
	[0 ... MAX_TYP-1] = ~0UL
};*/

int new_function(int *arr, int idx);

static inline
int init_array(int *arr, int limit)
{
	arr[0 ... limit-1] = 0UL;
}

int main(int argc, char *argv[])
{
	int arr[MAX_TYP];
	init_array(arr, MAX_TYP);
	new_function(arr, 0);
	return 0;
}


int new_function(int *arr, int idx)
{
	return arr[idx];
}

