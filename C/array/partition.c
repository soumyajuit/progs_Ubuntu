#include<stdio.h>
#include<stdlib.h>

#define MAX_LEN  100
#define SWAP(arr, i, j)		\
	do {			\
		int _t = arr[i];\
		arr[i] = arr[j];\
		arr[j] = _t;	\
	}while(0);

static int
partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int i = 0;
	int k = -1;

	for(i = start; i < end; i++) {
		if (arr[i] < pivot) {
			k++;
			SWAP(arr, k, i);
		}
	}
	
	k++;
	SWAP(arr, k, i);

	return k;
}

int
main(int argc, char *argv[])
{

	int len;
	int arr[MAX_LEN] = {0};
	int i = 0;
	int pivot = 0;

	scanf("%d", &len);
	for (i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}

	pivot = len/2;
	SWAP(arr, pivot, len-1);
	printf("\n pivot = %d\n", partition(arr, 0, len-1));

	for( i = 0; i < len; i++) {
		printf("\n %d", arr[i]);
	}

	return 0;
}



	
