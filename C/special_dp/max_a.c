#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{

	int len;
	
	len = atoi(argv[1]);

	printf("\n The max num is %d \n", get_max_A_num(len));

	return 0;
}


int
get_max_A_num(int len)
{

	int max_num_a_till_now[len+1];
	int i = 0;
	int j = 0;
	int curr = 0;
	int max_curr = 0;

	printf("\n sizeof(max_num_a_till_now) = %ld \n", sizeof(max_num_a_till_now));

	for(i = 1; i < 7 ; i++) {
		max_num_a_till_now[i] = i;
	}


	for(i = 7; i <= len; i++) {

		for(j = i-2; j > 0; j--) {
			curr  = (i-j-1) * max_num_a_till_now[j];
			max_curr = (curr > max_curr) ? curr : max_curr;
		}

		max_num_a_till_now[i] = max_curr;
	}

	return max_num_a_till_now[len];
}


