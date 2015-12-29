#include<stdio.h>

int main(int argc, char *argv[])
{

	int arr[10] = {0};
	int i = 0;


	arr[1]++;
	for(i = 0; i < 10; i++) {
		printf("\n %d", arr[i]);
	}

	return 0;
}
