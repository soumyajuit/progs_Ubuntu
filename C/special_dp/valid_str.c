#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<search.h>

#define MAX_DICT 1024
#define MAX_LEN	 1024

/* I did a simple dictionary implementation. Didn't do any kind of hashing/suffix trees */

char dict[MAX_DICT][MAX_LEN] = { "how",
				 "do",
				 "you",
				 "do",
				 "why",
				 "what",
				 "i",
				 "am",
				 "eating",
				 "rice",
				 "a",
				 "b",
				 "c",
				 "abc",
				 "ab",
				 "bc"};
int dict_contain = 16;

int main(int argc, char *argv[])
{

	char str[MAX_LEN];
	int len;
	int t_arr[MAX_LEN][MAX_LEN];
	int arr[MAX_LEN];


	memset(t_arr, 0, MAX_LEN*MAX_LEN*sizeof(int));
	strcpy(str, argv[1]);
	len = strlen(str);
	find_match(str, len, t_arr);
	printf("\n %d \n", print_match(len, 0, t_arr, arr, str));
	return 0;
}



/* Simple dictionary implementation */
int 
dict_find(char *src, int start, int len)
{
	int i = 0;
	char dst[MAX_LEN];

        strncpy(dst, src+start, len);

	for (i = 0; i < dict_contain; i++ ) {
		if (strcmp(dict[i] , dst) == 0) {
			return 1;
		}
	}
	return 0;
}
		


/* The DP solution to find valid prefixes */

int
find_match(char *str, int len, int tmp_arr[][MAX_LEN])
{

	int l=0;
	int i = 0;
	int j = 0;

	for (l = 1; l <= len; l++) {
		for (i = 0; i < len-l+1; i++) {
			j = i+l-1;

			if (dict_find(str, i, l)) {
				tmp_arr[i][j] = 1;
			}
		}
	}	

	return 0;
}


/* Cut the string from generated valid prefixes */

int
print_match(int len, int next_loc, int tmp_arr[][MAX_LEN], int arr[MAX_LEN], char *str)
{
	int i = 0;
	int ret = 0;
	if (next_loc == len) {
		return 1;
	}


	for (i = next_loc ; i < len; i++) {
		if (tmp_arr[next_loc][i]) {
			ret = 1;
			ret &= print_match(len, i+1, tmp_arr, arr, str);
			arr[i] = ret;
		}

		if (next_loc == 0) {
			if (!ret) {
				memset(arr, 0, len*sizeof(int));
			} else {
				print_valid_string(len, arr, str);
				ret = 0;
				memset(arr, 0, len*sizeof(int));
			}
		}

	}

	return ret;
} 

int
print_valid_string(int len, int arr[len], char*str)
{

	int i = 0;

	printf("\n result string is: ");
	for(i = 0; i < len; i ++) {
		if (arr[i] == 1) {
			printf("%c ", str[i]);
		} else {
			printf("%c", str[i]);
		}
	}
}


/*
 *
 * For debugging only


int
print_mat(int tmp_arr[][MAX_LEN], int len)
{

	int i =0;
	int j = 0;

	printf("\n");
	for(i = 0; i < len; i++) {
		for(j  = 0; j < len; j++) {
			printf("%d ", tmp_arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int
print_arr(int len, int* arr)
{

	int i= 0;
	for (i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
*/

