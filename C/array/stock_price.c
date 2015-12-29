#include<stdio.h>

#define MAX_LEN	100


int main(int argc, char *argv[])
{

	int n = 0;
	int i = 0;
	int arr[MAX_LEN];

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("\n The max profit is %d \n", find_max_profit_1(arr, n));

	return 0;

}


int
find_max_profit_1(int arr[], int n)
{
	int i = 0;
	int c_b = 0;
	int c_s = 0;
	int m_s = 0;
	int m_b = 0;
	int profit = 0;



	profit  = arr[c_s] - arr[c_b];

	for (i = 1; i < n; i++) {
		if (arr[i] < arr[c_b]) {
			c_b = i;
			continue;
		}

		if (arr[i] > arr[c_s]) {
			c_s = i;
		}

		if (profit < (arr[c_s] - arr[c_b])) {
			m_s = c_s;
			m_b = c_b;
			profit = arr[m_s] - arr[m_b];
		}
	}

	return profit;
}


