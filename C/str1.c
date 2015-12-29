#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN	1024

int make_str(char *dst, char *src, int start,
	     int len_dst, int len_src);
int simple_strncat(char *dst, char *src, int n);


int main(int argc, char *argv[])
{
	char arr[MAX_LEN] = "hello world";

	//printf("\n %s", strcat(arr, argv[1]));
	printf("\n %s   %d\n", arr, simple_strncat(arr+strlen(arr), argv[1], strlen(argv[1])));
	return 0;
}

int
simple_strncat(char *dst, char *src, int n)
{

	int i = 0;
	if (strlen(src) < n) {
		return -1;
	}

	while ( i < n) {
		dst[i] = src[i];
		i++;
	}

	dst[i] = '\0';	

	return n;
}

int
make_str(char *dst, char *src, int start,
	 int len_dst, int len_src)
{
	int len_added = 0;
	if (start + len_dst > len_src) {
		printf("\n something went wrong \n");
		return -1;
	}

	len_added = simple_strncat(dst+start, src, len_dst);

	if (len_added < 0) {
		printf("\n something went wrong \n");
		return -1;
	}	

	start += len_added;
	return start;
}

