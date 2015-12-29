#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN	70

static inline
get_int_index(char c) 
{
	char hex_char[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	if (c >= 48 && c <= 57) {
		return (c-48);
	}

	char c1  = toupper(c);
	return  10 + (c1 - 'A');
}

static inline int 
get_machine_type(void)
{
	int i = 1;
	char *ptr = (char*)&i;

	if (*ptr) {
		return 0;
	} else {
		return 1;
	}

	return 1;
}

static unsigned long long
convert_hex_to_dec(const char *hex_str, int len)
{
	unsigned long long num = 0;
	int count = 0;
	int shift_4 = 4;
	int i;
	int j = 0;
	int little_endian = get_machine_type();

	char *ptr = ((char*)&num);
	
	if (len/2 > sizeof(unsigned long long)) {
		return 0;
	}
	
	if (little_endian) {
		j = sizeof(unsigned long long) -1;
	}

	for(i = len-1; i >= 0; i--) {
		int k = get_int_index(hex_str[i]);
		if (count % 2 != 0) {
			k = k << shift_4;
		}

		ptr[j] |= k; 
		//printf("\n %d %d %d  %d \n", i , j, count, little_endian);
		if (!little_endian) {
			j = (count % 2 ? j+1 : j);
		} else {
			j = (count % 2 ? j-- : j);
		}
		count++;
	}

	return num;
}


int main(int argc, char *argv[])
{
	char str[MAX_LEN];
	int len = 0;	
	scanf("%s", str);
	len = strlen(str);
	printf("\n len is %d", len);
	printf("\n hulu \n");
	printf("\n %llu \n", convert_hex_to_dec(str, strlen(str)));
	return 0;
}



		
		
