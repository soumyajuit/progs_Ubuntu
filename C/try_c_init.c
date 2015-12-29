#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv)
{
	int num_v;
	
	printf("\n Enter num_v = \n");
	scanf("%d", &num_v);
	test_init_arr(num_v, 100);
	return 0;
}


int
test_init_arr(int num_v, int init)
{
	/* 
	 *  The init should only allow constant number of elements
	 *  to be initialized.
	 */
	int arr[100] = { [0 ... num_v] = init};
	int count;
	int i = 0;

	for(i = 0; i < num_v; i++)
	{
		arr[i] += i;
		count += arr[i];
	}

	return count;
} 
