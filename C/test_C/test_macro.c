#include<stdio.h>
#include<stdlib.h>



typedef struct some_s{
	int k1;
	int k2;
	int k3;
}some_t;

#define mymac(_s, _fi)	\
	(_s->k#_fi)



int 
main(int argc, char *argv[])
{

	some_t *s = (some_t*)malloc(sizeof(some_t));

	int i = 0 ;

	for (i = 1; i <= 3; i++) {
		mymac(s, i)  = 23;
		printf("\n %d", mymac(s, i));
	}
		
	return 0;
}
