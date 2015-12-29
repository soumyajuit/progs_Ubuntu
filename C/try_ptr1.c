#include<stdio.h>

int main(int argc, char *argv[])
{

	int *ptr;
	int a;
	int b = 10;

	ptr = &b;

	a = atoi(argv[1]);

	*ptr -= a;

	printf("\n a= %d, b=%d \n", a, *ptr);

	return 0;

}

	
