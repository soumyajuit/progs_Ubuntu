#include<stdio.h>
#include<stdlib.h>

#define DEP_HASH_MASK	12
#define DEP_MAX_ELE	(1 << DEP_HASH_MASK)
#define DEP_ELE_GET(dep_ele) (dep_ele & ((1 << DEP_HASH_MASK) - 1))
#define DEP_ELE_GET_LAST(dep_ele) (dep_ele >> DEP_HASH_MASK)

int show_ele(int* arr, int len);
int show_last_ele(int* arr, int len);

int main(int argc, char *argv[])
{
	int i=0;
	int arr[1024];
	int num_ele;	
	int t_ele;
	int last_ele;
	
	printf("\n Enter num ele =");
	scanf("%d", &num_ele);

	printf("\n Enter the number in sequence \n");
	for(i = 0; i < num_ele; i++) {
		scanf("%d", &t_ele);
		if (t_ele > DEP_MAX_ELE) {
			printf("\n wrong ele entered \n");
			exit(0);
		}
		t_ele = ((last_ele << DEP_HASH_MASK) | t_ele);
		arr[i] = t_ele;
		last_ele = i;
	}
	
	show_last_ele(arr, num_ele);
}
		

int
show_ele(int* arr, int len)
{
	int i = 0;

	printf("\n Printing elements \n");
	for(i = 0; i < len; i++) {
		printf("\n arr[%d] = %d", i, DEP_ELE_GET(arr[i]));
	}
}
			
int
show_last_ele(int* arr, int len)
{
	int i = 0;

	printf("\n Printing elements \n");
	for(i = 0; i < len; i++) {
		printf("\n arr[%d] = %d", i, DEP_ELE_GET_LAST(arr[i]));
	}
}
