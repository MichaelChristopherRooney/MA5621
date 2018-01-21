#include <stdio.h>
#include <stdlib.h>

void find_closest_ints(double num, double *low, double *high){
	int i;
	for(i = 1; i < num; i++){
		if(i * i > num){
			*low = i - 1;
			*high = i;
			return;
		}
	}
}

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Please provide a single float arg\n");
		return 1;
	}
	double num = atof(argv[1]);
	double low, high;
	find_closest_ints(num, &low, &high);
	while(high - low > 0.0000000001){
		printf("%.15f, %.15f\n", low, high);
		double guess = (low + high) / 2.0;
		if(guess * guess > num){
			high = guess;
		} else {
			low = guess;
		}
		
	}
	printf("%.15f, %.15f\n", low, high);
	return 0;
}
