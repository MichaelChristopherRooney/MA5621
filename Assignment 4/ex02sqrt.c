#include <stdio.h>
#include <stdlib.h>
#include <math.h> // for pow

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

#define MAX_ITERATIONS 100

// Cutoff point is when high - low is < 0.1^(num_decimal_places).
// So if num_digits is 3 this will stop when high - low < 0.001.
// Sometimes when num_decimal_places is large this will enter an infinite
// loop as rounding errors prevent (high - low) being less than the cutoff point.
// To fix this a maximum number of iterations is enforced.
double find_sqrt(double num, int num_decimal_places){
	double cutoff = pow(0.1, num_decimal_places);
	double low, high;
	find_closest_ints(num, &low, &high);
	int count = 0;
	while(high - low > cutoff && count < MAX_ITERATIONS){
		double guess = (low + high) / 2.0;
		if(guess * guess > num){
			high = guess;
		} else {
			low = guess;
		}
		count++;
	}
	return (high + low) / 2.0;
}

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("Expected usage: ./ex02 number num_decimal_places\n");
		return 1;
	}
	double num = atof(argv[1]);
	int num_decimal_places = atoi(argv[2]);
	double res = find_sqrt(num, num_decimal_places);
	printf("%f\n", res);
	return 0;
}
