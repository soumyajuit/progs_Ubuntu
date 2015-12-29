#include<stdio.h>
#include<stdlib.h>


#define MAX_LEN	1024

static int
binsearch(int arr[], int len, int key)
{
	int l = 0;
	int u = len -1;
	int index = -1;
	int mid; 

	while(l <= u) {
		mid = l + ((u - l)/2);

		if (arr[mid] < key) {
			l = mid + 1;
		} else if (arr[mid] > key) {
			l = mid -1;
		} else {
			index = mid;
			break;
		}
	}

	return index;
}


static int
binsearch_first_occurance(int arr[], int len, int key)
{
	int l = 0;
	int u = len -1;
	int mid = l + (u -l)/2;
	int index = -1;

	while(l <= u) {
		mid = l + (u -l)/2;

		if (arr[mid] < key) {
			l = mid + 1;
			index = mid;
		} else if (arr[mid] >= key) {
			u = mid - 1;
		}
	}

	if (index == -1 || index == len -1) {
		return -1;
	}

	return (index+1);
}

	




int main(int argc, char *argv[])
{

	int arr[MAX_LEN];
	int len;
	int key;
	int i = 0;
	int index = 0;

	scanf("%d", &len);

	for( i = 0 ; i < len; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &key);

	index = binsearch(arr, len, key);

	if (index > -1) {
		printf("\n the value is = %d and found at the index = %d\n", arr[index], index);
	}

	index = binsearch_first_occurance(arr, len, key); 
	printf("\n The index found is %d and value is %d \n", index, (index >= 0 ? arr[index] : -1));
}



