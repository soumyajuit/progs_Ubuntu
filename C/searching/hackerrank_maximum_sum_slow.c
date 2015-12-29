#include<stdio.h>

#define MAX_LEN 100000	
#define MAX(a,b)	((a > b) ? a : b)

unsigned long int 
find_max_mod_slow(unsigned long int arr[], int n, unsigned long int m);


int main(int argc, char *argv[])
{
	int i = 0;
	int n = 0;
	int num_test_cases = 0;
	unsigned long int arr[MAX_LEN];
	unsigned long int m = 0;

	scanf("%d", &num_test_cases);
	while(num_test_cases > 0) {
		scanf("%d", &n);
		scanf("%lu", &m);
		for(i = 0; i < n; i++) {
			scanf("%lu", &arr[i]);
		}
		printf("%lu\n", find_max_mod_slow(arr, n, m));
		num_test_cases--;
	}

	return 0;
}


unsigned long int 
find_max_mod_slow(unsigned long int arr[], int n, unsigned long int m)
{
	int i = 0;
	int j = 0;
	int k = 0;

	unsigned long int cur_sum = 0;
	unsigned long int max_sum_found = 0;

	for(i = 1; i < n; i++) {
		k = 0;
		cur_sum = 0;
		while(k < i) {
			cur_sum += arr[k];
			k++;
		}
		max_sum_found = MAX(max_sum_found, cur_sum%m);

		for(j = k; j < n-k+1; j++) {
			cur_sum -= arr[j-k];
			cur_sum += arr[j];
			max_sum_found = MAX(max_sum_found,cur_sum%m);
		}
	}

	return max_sum_found;
}



