#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{

	int len = 0;
	char *str = NULL;

	str = strdup(argv[1]);
	len = strlen(str);

	printf("\n The lenght = %d, the string = %s \n", len, str);
	printf("\n The longest palin length %d \n", get_long_palindrom(len, str));

	return 0;
}




int
get_long_palindrom(int len, char *str)
{

	int palin_mat[len][len];
	int i = 0;
	int j = 0;
	int k = 0;
	int max_len = 0;

	memset(palin_mat, 0, sizeof(int)*len*len);

	for(i=0; i<len; i++) {
		palin_mat[i][i] = 1;
	}

	for(i =0; i < len-1; i++) {
		if (str[i] == str[i+1]){
			palin_mat[i][i+1] = palin_mat[i][i]+palin_mat[i+1][i+1];
			max_len = palin_mat[i][i+1];
		}
	}

	print_palin_mat(len, palin_mat);

	printf("\n the length of max_len = %d\n", max_len);

	for(i = 2; i <= len; i++) {
		k = len - i+1;

		for(j=0; j < k; j++) {
			printf("\n %c %d %c %d enrty = %d and i=%d\n", str[j], j+1 , str[j+i-1], (j+i-2), palin_mat[j+1][j+i-2], i);

			if (str[j] == str[j+i-1] && palin_mat[j+1][j+i-2]) {
				printf("\n entered here \n");
				palin_mat[j][j+i-1] = 2 + palin_mat[j+1][j+i-2];
				max_len = max_len < palin_mat[j][j+i-1] ? palin_mat[j][j+i-1] : max_len;
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


			
