#include<stdio.h>
#include<stdlib.h>

#define MAX_LEN		100000
#define MAX(a,b)	((a > b) ? a : b)

unsigned long int
find_max_modulo(unsigned long int arr[], int n, unsigned long int m);

int main(int argc, char *argv[])
{
	int n;
	int i;
	unsigned long int m;
	unsigned long arr[MAX_LEN];
	int num_test_cases = 0;

	scanf("%d", &num_test_cases);

	while(num_test_cases > 0) {
		scanf("%d", &n);
		scanf("%lu", &m);

		for(i = 0; i < n; i++) {
			scanf("%lu", &arr[i]);
		}

		printf("found max len %lu\n", find_max_modulo(arr, n, m));
		num_test_cases--;
	}

	return 0;
}


unsigned long int
find_max_modulo(unsigned long int arr[], int n, unsigned long int m)
{

	int start = 0;
	int i = 0;
	unsigned long int cur_sum = 0;
	unsigned long int max_sum_found = 0;
	
	for(i = 0; i < n; i++) {
		arr[i] = (arr[i] % m);
	}

	for(i = 0; i < n; i++) {

		while(cur_sum > m && start < (i-1)) {
			cur_sum -= arr[start];
			start++;
		}

		max_sum_found = MAX(max_sum_found, cur_sum%m);
		cur_sum += arr[i];
	}

	return max_sum_found;
}

