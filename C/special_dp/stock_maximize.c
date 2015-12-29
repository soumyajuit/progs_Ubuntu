#include<stdio.h>

#define MAX_ARR_LEN	50000	


unsigned long max_profit(unsigned long  arr[], int len);

int main(int argc, char *argv[])
{

	unsigned long  arr[MAX_ARR_LEN] = {0};
	int		 len = 0;
	int		 i = 0;
	int		 num_test = 0;

	scanf("%d", &num_test);

	while(num_test > 0) {

		scanf("%d", &len);
		for(i = 0; i < len; i++) {
			scanf("%lu", &arr[i]);
		}

		printf("%lu \n", max_profit(arr, len));
		num_test--;
	}

	return 0;
}

unsigned long 
max_profit(unsigned long arr[], int len)
{

	int i = 0;
	int cur_max = 0;
	unsigned long  profit = 0;
	cur_max = len-1;

	for (i = len-1; i >= 0; i--) {
		if (arr[i] < arr[cur_max]) {
			profit += arr[cur_max] - arr[i];
		} else {
			cur_max = i;
		}
	}

	return profit;
}



