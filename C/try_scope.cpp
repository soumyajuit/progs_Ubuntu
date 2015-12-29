#include<stdio.h>


int a = 50;

int main(int argc, char *argv[]) 
{

	int a = 0;
	a = 10;

	printf("\n %d %d", a, ::a);

	return 0;
}
