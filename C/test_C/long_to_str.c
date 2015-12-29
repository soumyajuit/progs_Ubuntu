#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_NUM_LEN	100

#define SWAP(a,b)		\
	do {			\
		a = a-b;	\
		b = a + (a-b);	\
		a = b - (a-b);	\
	}while(0);

int main(int argc, char *argv[])
{

	char arr[MAX_NUM_LEN] = {'\0'};
	char *str;
	int len;
	unsigned long num;

	scanf("%lu", &num);
//	len = long_to_str(num, arr);

	strcpy(arr, argv[1]);
	reverse(arr, strlen(arr));
	printf("\n %s", arr);

	return;
}
	
int
long_to_str(unsigned long num, char arr[])
{

	int i=0;

	while(num > 0) {
		arr[i++] = num%10;
		num = num/10;
	}

	arr[i] = '\0';

	return i;
}


int
reverse(char arr[], int len)
{

	int i = 0;
	int t_c=0;
	for (i = 0; i < len/2; i++) {
		t_c = arr[i];
		arr[i] = arr[len-1-i];
		arr[len-1-i] = t_c;
	}

	return i;
}

