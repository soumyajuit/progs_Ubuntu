#include<stdio.h>
#include<stdlib.h>


#define MAX_SIZE	1024
#define PUSH(lcs_stack, cur_pos, size,ele)			\
	do {							\
		if (cur_pos > size-1) {				\
			printf("\n Some error occurred \n");	\
			exit(0);				\
		}						\
		lcs_stack[cur_pos++] = ele;			\
	}while(0)



int main(int argc, char *argv[])
{

	int arr[MAX_SIZE];
	int lcs_arr[MAX_SIZE];
	int lcs_arr_end[MAX_SIZE];
	int count;
	int i = 0;
	int max_lcs_end_here = 0;

	scanf("%d", &count);

	for (i = 0; i < count; i++) {
		scanf("%d", &arr[i]);
	}

	printf("\n max_end_here = %d \n",
		(max_lcs_end_here = find_lcs(arr, lcs_arr, lcs_arr_end, count)));
	print_arr(lcs_arr_end, count);
	print_lcs(arr, lcs_arr_end, max_lcs_end_here,count);
	return 0;
}


int
find_lcs(int arr[], int lcs_arr[], int lcs_arr_end[], int n)
{

	int i = 0;
	int j = 0;
	int max_lcs = 0;
	int max_lcs_end = 0;

	for(i = 0; i < n; i++) {
		lcs_arr[i] = 0;
		lcs_arr_end[i] = 0;
	}


	for (i = 0; i < n ; i++) {
		for (j = 0; j < i ; j++) {
			if (arr[i] > arr[j]) {
				if (lcs_arr[i] < (lcs_arr[j] + 1)) {
					printf("\n i = %d, lcs = %d , new_lcs = %d, new_j = %d", i, lcs_arr[i], lcs_arr[j]+1, j);
					lcs_arr[i] = lcs_arr[j] + 1;
					lcs_arr_end[i] = j;
				}
			}
		}

		if (max_lcs  < lcs_arr[i]) {
			max_lcs = lcs_arr[i];
			max_lcs_end = i;
			//printf("\n max_lcs_end = %d , max_lcs_prev = %d", i, lcs_arr[i]);
		}
	}

	return max_lcs_end;
}


int
print_lcs(int arr[], int lcs_arr[], int max_lcs_end_here, int size)
{

	int lcs_stack[MAX_SIZE];
	int ele = 0;
	int cur_pos_arr = max_lcs_end_here;
	int cur_pos = 0;
	int cur_pos_tmp = 0;
	int loop_end = 0;

	while(!loop_end) {
		ele = arr[cur_pos_arr];
		PUSH(lcs_stack, cur_pos, size,ele);
		cur_pos_arr = lcs_arr[cur_pos_arr];
		if (cur_pos_arr == 0) {
			loop_end = 1;
		}

	}
		
	cur_pos_tmp = cur_pos-1;

	while(cur_pos_tmp >= 0 ) {
		printf("\n %d", lcs_stack[cur_pos_tmp--]);
	} 

	return cur_pos;
}

int
print_arr(int lcs_arr[], int count)
{

	int  i =0;

	for(i = 0; i < count; i++) {
		printf("\n %d", lcs_arr[i]);
	}
	return 0;
}




