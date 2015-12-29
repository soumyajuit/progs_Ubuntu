#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{

	int fd = 0;
	int num = 0;
	
	while(scanf("%d", &num) != EOF) {
		printf("\n%d", num);
	}

	return 0;
}

