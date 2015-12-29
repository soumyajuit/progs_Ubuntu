#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_NUM	1024

long find_primes(int n);

int main(int argc, char *argv[])
{
	int n;

	scanf("%d", &n);
	printf("\n %lu", find_primes(n));
	return 0;
}


long find_primes(int n)
{

	unsigned long int p_arr[MAX_NUM];
	unsigned long n_lt;
	long p_found;
	unsigned long i = 0;
	unsigned long j = 0;

	if (n/log2(n) >= (MAX_NUM -10)) {
		return 0;
	}
	n_lt = (n/log2(n)) + 10;

	p_arr[0] = 2;
	p_arr[1] = 3;
	p_found = 2;

	for (i = 4; i <= n; i++) {
		int not_prime = 0;
		for (j = j; j < p_found; j++) {
			if (i % p_arr[j] == 0) {
				not_prime = 1;
				break;
			}
		}

		printf("\n enterd here \n");
		if (!not_prime) {
			p_arr[p_found] = i;
			p_found++;
		}
	}

	return p_found;
}





