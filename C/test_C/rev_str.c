#include<stdio.h>
#include<string.h>

#define MAX_LEN		1024
#define SWAP(arr,i,j)		\
	do{			\
		int _t = arr[i];\
		arr[i] = arr[j];\
		arr[j] = _t;	\
	}while(0);

#define SPACE(i) (i == ' ')

char* rev_str(char *str, int len);


int main(int argc, char *argv[])
{
	int arr[2] = {1,2};
	char str[MAX_LEN];
	SWAP(arr,0,1);
	strcpy(str, argv[1]);
	rev_str(str, strlen(str));
	//printf("\n %d %d \n", arr[0], arr[1]);
	printf("\n %s", str);
	return 0;
}


char*
rev_str(char *str, int len)
{

	int i = 0;

	for(i = 0; i < len/2; i++) {
		SWAP(str,i,len-i-1);	
	}

	return str;
}

char*
rev_words(char *para, int len)
{
	int i = 0;
	int k = 0;

	char *str = rev_str(para, len);
	char *cur_ptr = str;

	/* assumption is words are single space apart */
	for(i = 0; i < len; i++) {
		if (SPACE(str[i])) {
			rev_str(cur_ptr, k);
			cur_ptr = cur_ptr + k+1;
			k = 0;
		} else {
			k++;
		}
	}

	return str;
}
		

