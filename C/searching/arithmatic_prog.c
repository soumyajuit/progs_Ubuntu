#include<stdio.h>

#define MAX_ELE	2500

unsigned long int missing_ele(void);

int main(int argc, char *argv[])
{
	(void)missing_ele();
	return 0;
}


unsigned long int
missing_ele(void)
{

	int i = 0;
	int len = 0;
	unsigned long int exp_diff = 0;
	unsigned long int miss_ele = 0;
	unsigned long int arr[MAX_ELE]; 

	scanf("%d", &len);
	scanf("%lu", &arr[0]);
	scanf("%lu", &arr[1]);

	exp_diff = arr[1] - arr[0];
	miss_ele = arr[0];

	for (i = 2; i < len; i++) {
		scanf("%lu", &arr[i]);
		if ((arr[i] - arr[i-1]) > exp_diff) {
			printf("\n miss_ele = %lu", miss_ele);
			printf("\n exp_diff = %lu", exp_diff);
			miss_ele = arr[i-1];
			printf("\n miss_ele = %lu", miss_ele);
		} else if ((arr[i] - arr[i-1]) < exp_diff) {
			printf("\n exp_diff = %lu", exp_diff);
			exp_diff = arr[i] - arr[i-1];
			printf("\n exp_diff = %lu", exp_diff);
		}
	}

	printf("\n %lu", exp_diff);
	return (miss_ele + exp_diff);
}
