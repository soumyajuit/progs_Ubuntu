#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE	1024

#define SWAP(_arr, _i, _j)		\
	do {				\
		int _t = _arr[_i];		\
		_arr[_i] = _arr[_j];	\
		_arr[_j] = _t;		\
	} while(0);

static inline int
match_found(int num, int mod_num, int arr_i)
{
	if (arr_i == num) {
		return 1;
	}

	return 0;

}

int main(int argc, char *argv[])
{
	int arr[MAX_SIZE];
	int i = 0;
	int count;
	int last_idx = -1;
	int mod_count = 0;

	int mod_num = 0;
	int num = 0;
	
	scanf("%d", &count);
	for(i = 0; i < count; i++) {
		scanf("%d", &arr[i]);
	}

	num = atol(argv[1]);
	mod_num = atol(argv[2]);

	for( i = 0; i < count; i++) {
		if (match_found(num, mod_num, arr[i])) {
			if (last_idx < i-1) {
				SWAP(arr, last_idx+1, i);
			}
			last_idx++;
			mod_count++;
		}
	}

	for(i = 0; i < count; i++) {
		printf("\n%d", arr[i]);
	}
}
