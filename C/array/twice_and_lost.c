#include<stdio.h>
#include<stdlib.h>


#define MAX_LEN	1024

static int
find_ele(int arr[], int len, int *a, int *b)
{
	unsigned long long sum = 0;
	unsigned long long sum_squared = 0;

	unsigned long long sum_arr = 0;
	unsigned long long sum_squared_arr = 0;

	long int diff;
	long int diff_squared;
	long long diff_plus = 0;

	int x,y;

	int i = 0;

	for (i = 0; i < len; i++) {
		sum_arr += arr[i];
		sum_squared_arr += (arr[i] * arr[i]);

		sum += (i+1);
		sum_squared += ((i+1) * (i+1));
	}

	diff = sum_arr - sum; /* x - y */
	diff_squared = sum_squared_arr - sum_squared; /* x^2 - y^2 */

	diff_plus = (diff_squared / diff); /* x + y */

	x = diff_plus + diff;
	y = diff_plus - diff;

	*a = x/2;
	*b = y/2;

	//printf("\n A = %d, B = %d \n", x, y);

	return 0;
}


int main(int argc, char *argv[])
{
	int arr[MAX_LEN];

	int i = 0;
	int len = 0;
	int a, b;

	scanf("%d", &len);

	for(i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}

	find_ele(arr, i, &a, &b);
	printf("\n A = %d, B = %d\n", a, b); 

	return 0;
}



