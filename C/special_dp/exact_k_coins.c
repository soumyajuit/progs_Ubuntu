#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_LEN	1024


static int
get_exact_coin_path(int **mat, int n, int m, int k)
{
	int arr[n][m][k+1];
	int i = 0;
	int j = 0;
	int p = 0;

	memset(arr, 0, sizeof(arr));

	printf("\n test1 \n");

/*
	for (i = 0; i < n; i ++) {
		for( j = 0; j < m; j++) {
			for( p = 0; p <= k; p++) {
				printf("\n arr[%d][%d][%d] = %d", i, j, p, arr[i][j][p]);
			}
		}
	}

*/
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			if (i == 0 && j == 0 && mat[i][j] <= k) {
				arr[0][0][mat[i][j]] = 1;
				printf("\n entered \n");
				continue;
			}

			for(p = 0; p <= k; p++) {
				if ((i-1) >= 0 && arr[i-1][j][p] >0 &&
				    (p + mat[i][j] <= k)) {
					arr[i][j][p+mat[i][j]] = arr[i-1][j][p];
				}

				if ((j-1) >= 0 && arr[i][j-1][p] > 0 &&
				    (p + mat[i][j] <= k)) {
					arr[i][j][p + mat[i][j]] += arr[i][j-1][p];
				}

			}

		}

	}


	printf("\n test3 \n");
	return arr[n-1][m-1][k];
}



int main(int argc, char *argv[])
{

	int **arr;
	int i = 0;
	int j = 0;

	int n = 0;
	int m = 0;
	int k = 0;

	memset(arr, 0, sizeof(int)*n*m);

	scanf("%d %d", &n, &m);

	arr = (int**)malloc(sizeof(int*)*n);

	if (arr == NULL) {
		exit(0);
	}
	for (i =0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int)*m);
		if (arr[i] == NULL) {
			exit(0);
		}
	}

	for(i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	printf("\n test \n");
	scanf("%d", &k);
	printf("\n %d \n", get_exact_coin_path((int**)arr, n, m, k));

	return;
}






