#include<stdio.h>
#include<stdlib.h>

#define MAX_LEN 1024

int qsort_comp(const void *ele1, const void *ele2);

int main(int argc, char* argv[])
{

	int i = 0;
	int n = 0;
	int arr[MAX_LEN];

	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}	
	qsort(arr, n, sizeof(int), qsort_comp);

	for(i = 0; i < n; i++) {
		printf("\n%d", arr[i]);
	}	
	return 0;
}





int
qsort_comp(const void *ele1, const void *ele2)
{
	return ((*((int*)ele1)) -  (*((int*)ele2)));
}

