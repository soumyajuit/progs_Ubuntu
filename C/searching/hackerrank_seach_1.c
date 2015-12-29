#include<stdio.h>
#include<stdlib.h>

#define MAX_LEN 100000

int main(int argc, char *argv[])
{

	int num_test_cases = 0;
	int num_ele = 0;
	int arr[MAX_LEN];

	scanf("%d", &num_test_cases);

	while(num_test_cases > 0) {

		scanf("%d", &num_ele);
		int i = 0;

		for(i = 0; i < num_ele; i++) {
			scanf("%d", &arr[i]);
		}
		if (find_ele_left_right(arr, num_ele)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		num_test_cases--;
	}

	return 0;
}


int
find_ele_left_right(int arr[], int n)
{

	int found_ele = 0;
	int i =0;
	int left_sum = 0;
	int right_sum = 0;

	if(n < 3) {
		return 0;
	}

	left_sum = arr[0];

	for(i = 2; i < n; i++) {
		right_sum += arr[i];
	}


	if (left_sum == right_sum) {
		found_ele = 1;
	}

	for(i = 2; i < n-1; i++) {
		left_sum += arr[i-1];
		right_sum -= arr[i];

		if (left_sum == right_sum) {
			found_ele = 1;
		}
	}

	return found_ele;
}

