#include<stdio.h>
#include<stdlib.h>


#define MAX_LEN	1024


int main(int argc, char *argv[])
{

	int len = 0;
	int arr[MAX_LEN] = {0};
	int i = 0;
	int k = 0;

	scanf("%d", &len);

	for(i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}

	printf("\n enter the key:");
	scanf("%d", &k);

	binsearch(arr, len, k);

	return 0;
}

int printarr(int arr[], int len)
{
	int i = 0;

	for(i = 0; i < len; i++) {
		printf("\n %d", arr[i]);
	}
	return 0;
}


int binsearch(int arr[], int len, int k)
{

	int lo = 0;
	int hi = len-1;
	int mid = (lo+hi)/2;

	while(lo <= hi) {
		if (arr[mid] > k ) {
			hi = mid-1;
		} else if (arr[mid] < k) {
			lo = mid+1;
		} else {
			printf("\n %d", mid);
			break;
		}
		mid = (lo + hi)/2;
	}

	printf("\n %d Not found \n", k);
	return len+1;
}


