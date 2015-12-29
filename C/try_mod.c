#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(int argc, char *argv[])
{

	return 0;
}


unsigned long int 
fast_fact_mod(int n, int mod)
{
	return ((n == 1) ? 1 : (((n % mod) * (fast_fact_mod(n-1, mod) % mod)) % mod));
}


unsigned long int
set_interset_core(int *edge1, int *edge2)
{
	int i = 0;
	int j  = 0;

	for ( i = 0; i < num ; i++) {
		if (edge2[0] == edge_set[i]) {
			count++;
		}
	}

}
