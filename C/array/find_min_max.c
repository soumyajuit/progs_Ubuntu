#include<stdio.h>
#include<stdlib.h>


static int
find_min(int arr[], int len)
{
	int i = 0;
	int k = 0;

	for(n = len; n >= 0; n=n/2)
	while(i < n-1) {
		if (arr[i] < arr[i+1]) {
			small = i;
		} else {
			small = i+1;
		}

		SWAP(arr, small, k);
		k++;
		i = i+2;
	}

	
