#include<stdio.h>
#include<stdlib.h>

#define MAX_ROW 1024
#define MAX_COL 1024
#define MIN(a, b, c) ((a > b) ?			\
			((b > c) ? c : b) :	\
			((a > c) ? c : a))

int find_special_mat(int **arr, int col, int row);
int** create_arr(int row, int col);
int populate_mat(int** arr, int row, int col);

int main(int argc, char *argv[])
{
	int **arr = NULL;
	int row = 0;
	int col = 0;

	scanf("%d %d", &row, &col);
	arr = create_arr(row, col);

	populate_mat(arr, row, col);
	find_special_mat(arr, col, row);

	return 0;
}


int**
create_arr(int row, int col)
{

	int** t_arr = NULL;
	int i = 0;

	t_arr = (int**) malloc(sizeof(int*)*row);

	if (t_arr == NULL) {
		return NULL;
	}

	for( i = 0; i < row; i++) {
		t_arr[i] = (int*)malloc(sizeof(int)*col);	
		if(t_arr[i] == NULL) {
			return NULL;
		}
	}

	return t_arr;
}


int
populate_mat(int** arr, int row, int col)
{

	int i,j;

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	return i*j;
}


int
find_special_mat(int **arr, int col, int row)
{

	int t_arr[row][col];
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++) {
		t_arr[i][0] = arr[i][0];
	}

	for(j = 0; j < col; j++) {
		t_arr[0][j] = arr[0][j];
	}

	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++) {
			if (arr[i][j] == 0) {
				t_arr[i][j] = 0;
			} else {
				t_arr[i][j] = MIN(t_arr[i][j-1],
						  t_arr[i-1][j], t_arr[i-1][j-1]) + 1;
			}
		}
	}


	for(i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d ", t_arr[i][j]);
		}
		printf("\n");
	}


	return 0;
}

