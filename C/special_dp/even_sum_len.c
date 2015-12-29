#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_LEN 1024

int main(int argc, char *argv[])
{

	int len = 0;
	int arr[MAX_LEN];
	int i = 0;
	scanf("%d", &len);

	for(i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}

	printf("\n The longest palin length %d \n", get_long_palindrom(len, arr));

	return 0;
}




int
get_long_palindrom(int len, int arr[len])
{

	int palin_mat[len][len];
	int i = 0;
	int j = 0;
	int k = 0;
	int max_len = 0;

	memset(palin_mat, 0, sizeof(int)*len*len);

	for(i = 0; i < len; i++) {
		palin_mat[i][i] = arr[i];
	}

	for(i =0; i < len-1; i++) {
		palin_mat[i][i+1] = arr[i] + arr[i+1];
		max_len = max_len < palin_mat[i][i+1] ? palin_mat[i][i+1] : max_len;
	}

	print_palin_mat(len, palin_mat);

	for(i = 4; i <= len; i++) {

		for(j=0; j < len-i+1; j++) {
			k = j+i-1;
			printf("\n %c %d %c %d enrty = %d and i=%d\n", arr[j], j+1 , arr[j+i-1], (j+i-2), palin_mat[j+1][j+i-2], i);

			if (arr[j] == arr[k] && (
			    (palin_mat[j+1][k-1]) {
				printf("\n entered here \n");
				palin_mat[j][k] = arr[j] + arr[k] + palin_mat[j+1][k-1];
				max_len = max_len < palin_mat[j][k] ? palin_mat[j][k] : max_len;
			} else {
				palin_mat[j][k] = 0;
			}

		}
	}

	print_palin_mat(len, palin_mat);
	return max_len;

}

int
print_palin_mat(int len, int palin_mat[][len])
{

	int i,j;

	for(i = 0; i < len; i++) {
		printf("\n palin_mat[%d] = ", i);
		for(j = 0; j < len; j++) {
			printf(" %d", palin_mat[i][j]);
		}
	}

	return 0;
}


			
