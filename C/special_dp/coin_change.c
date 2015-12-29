#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_COINS	10

static int
coin_change(int coins[], int coin_len, int value)
{

	int arr[coin_len][value+1];

	memset(arr, 0, sizeof(int)*coin_len*value);
	int i = 0;
	int j = 0;

	for (j = 0 ; j < coin_len; j++) {
		arr[j][0] = 1;
	}

	for(i = 1; i <= value; i++) {
		int coeffi_x = 0;
		int coeffi_0 = 0;
		for (j = 0; j < coin_len; j++) {
			coeffi_0 = (j-1) >= 0 ? arr[j-1][i] : 0;
			coeffi_x = (i < coins[j]) ? 0 : arr[j][i-coins[j]];

			arr[j][i] = coeffi_0 + coeffi_x;
			printf("\n i= %d coin = %d coeffi_0=%d coeffi_x= %d", i, coins[j], coeffi_0, coeffi_x);
		}
	}

	return arr[coin_len-1][value];
}

int main(int argc, char *argv[])
{
	int len = 0 ;
	int i = 0;
	int coins[MAX_COINS] = {0};
	int value;

	scanf("%d", &len);

	for( i = 0 ; i < len; i++) {
		scanf("%d", &coins[i]);
	}

	scanf("%d", &value);

	printf("\n Total # ways = %d \n", coin_change(coins, len, value));
	return 0;
}




