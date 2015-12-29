#include<stdio.h>


static inline int
compare_64(const unsigned long *k1, const unsigned long *k2)
{
	printf("\n %p %p", k1, k2);
	return ( (*k1 == *k2) ? 0 : ( *k1 > *k2 ? 1 : -1));
}

static inline int
compare_name(const char *name1, const char *name2)
{
	int ret = 0;
	return ((ret = compare_64((unsigned long *)name1++, (unsigned long *)name2++)) != 0 ? ret:
		 compare_64((unsigned long *)name1, (unsigned long *)name2));
}


int
main(int argc, char *argv[])
{

	char name1[16];
	char name2[16];
	unsigned long a1;
	unsigned long a2;
	unsigned long b1;
	unsigned long b2;

	char *p1;
	char *p2;

	int k = 0;
	int i = 0;

	/* As per testing requirement I am taking the value as unsigned long
	 * But in the actual scenario the 128 input should be taken as a bit
	 * string.
	 */
	scanf("%lu %lu", &a1, &a2);
	scanf("%lu %lu", &b1, &b2);

	printf("\n %p %p %p %p \n", name1, name2, name1+1, name2+1);
	printf("\n %lu \n", sizeof(unsigned long));

	p1 = (char*)&a1;
	p2 = (char*)&b1;

	for(i = 0; i < sizeof(unsigned long); i++) {
		name1[k] = *p1++;
		name2[k] = *p2++;
		k++;
	}

	p1 = (char*)&a2;
	p2 = (char*)&b2;

	printf("\n k = %d", k);
	for(i = 0; i < sizeof(unsigned long); i++) {
		name1[k] = *p1++;
		name2[k] = *p2++;
		k++;
	}
	printf("\n k = %d", k);

	printf("The comparasion result is following %d \n", compare_name(name1, name2));

	return 0;
}

	

	

