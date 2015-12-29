#include<stdio.h>
#include<string.h>

#define MAX_DICT 1024
#define MAX_LEN  1024


char dict[MAX_DICT][MAX_LEN] = { "how",
                                 "do",
                                 "you",
                                 "do",
                                 "why",
                                 "what"};
int dic_contain = 6;




int main(int argc, char*argv[])
{

	char dst[1024];
	char *src = argv[3];
	int start = atoi(argv[1]);
	int len = atoi(argv[2]);

	strncpy(dst, src+start, len);

	printf("\n %s %u", dst, strlen(dst));
	return 0;
}
