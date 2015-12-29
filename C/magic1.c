#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define WHITE 1 
#define BLACK 2 
#define UNDEFIND 3 



int return_ball_color(int black, int white);

int main(int argc, char* argv[])
{
	int white = 0;
	int black = 0;
	int color = 0;
	int num_test_cases = 0;

	scanf("%d", &num_test_cases);
	printf("\n num_test_cases = %d \n", num_test_cases);
	while(num_test_cases) {

		scanf("%d %d", &white, &black);
		printf("\n white = %d black = %d \n", white, black);
		color = return_ball_color(black, white);

		switch(color) {
	
			case WHITE:
				printf("\n W");
				break;
			case BLACK:
				printf("\n B");
				break;
			default:
				printf("\n X");
		}
				num_test_cases--;
	}

	return 0;
}


int
return_ball_color(int black, int white)
{

	int color = 0;
	int color1 = 0;
	int color2 = 0;
	int black_t = 0;
	int white_t = 0;
	

	if (black == 0) {
		return WHITE;
	}

	printf("\n White = %d black = %d \n", white, black);
	black_t = ((black - 2) < 0 ? 0 : (black - 2));
	color1 = return_ball_color(black_t, white + 1);
	if (white > 0) {
		white_t = ((white - 1) < 0 ? 0 : (white - 1));
		color2 = return_ball_color(black, white_t);
	}

	if (color1 != color2) {
		color = UNDEFIND;
	} else {
		color = color1;
	}

	return color;
}


