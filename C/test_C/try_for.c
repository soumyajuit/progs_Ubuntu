#include<stdio.h>


int main(int argc, char *argv[])
{
	int i = 0;
	int len =0 ;
	

	scanf("%d", &len);

	for(i= len; i >= 0; i = i/2) {
		printf("\n %d", i);
		if(i == 0) {
			break;
		}
	}

	return 0;
}

