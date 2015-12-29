#include<stdio.h>

#define MAX_ELE_NUM 10
#define MAX_ELE (MAX_ELE_NUM + 1)
#define SENTINAL_ELE 0
#define MAX_SET 30

int enter_set(int *set, int n_ele);
//void display_sets(int **set, int num_set);
void display_sets(int set[][MAX_ELE], int num_set);
int print_set(int *set);

int main(int argc, char *argv[])
{

	int n_set = 0;
	int n_ele = 0;
	int i = 0;
	int set[MAX_SET][MAX_ELE];

	scanf("%d", &n_set);
	
	for ( i = 0; i < n_set; i++) {
		scanf("%d", &n_ele);
		enter_set(set[i], n_ele);
	}

	display_sets(set, n_set);
}


int
enter_set(int *set, int n_ele)
{
	int i=0;

	for( i = 1; i <= n_ele; i++) {
		scanf("%d", &set[i]);
	}

	set[0] = n_ele;
	return 0;
}
		
/*
void
display_sets(int **set, int n_set)*/

void
display_sets(int set[][MAX_ELE], int n_set)
{
	int i = 0;

	for (i = 0; i < n_set; i++) {
		printf("\n set[%d] \t", i);
		print_set(set[i]); 
	}
}

int
print_set(int *set)
{
	int i = 0;
	int n_ele = set[0];
	printf("[ ");

	for (i = 1; i <= n_ele; i++) {
		printf("%d ", set[i]);
	}

	printf("]\n");

	return n_ele;

}


