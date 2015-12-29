#include<stdio.h>
#include<stdlib.h>

#define MEM_FAILURE()							\
	do{								\
		printf("\n Memory failure in function "			\
			   "%s at %d line \n", __FUNCTION__, __LINE__);	\
		exit(0);						\
	} while(0);



int main(int argc, char* argv[])
{
	int take_val;

	take_val = atoi(argv[1]);

	if (take_val > 0) {
		MEM_FAILURE();
	}

	return 0;
}
