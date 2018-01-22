#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// We use sqrt from here for a comparison against our sqrt implementation
#include <math.h> 

double find_sqrt(double num, int num_decimal_places);

static int NUM_FAILED_TESTS = 0;

static void test_sqrt(){
	double args[] = { 10.0, 100.0, 123.0, 783.0, 1000.0, 1000000.0 };
	int num_decimal_places[] = { 3, 4, 5, 6, 7, 8};
	int i;
	for(i = 0; i < sizeof(args) / sizeof(args[0]); i++){
		double actual = sqrt(args[i]);
		double est = find_sqrt(args[i], num_decimal_places[i]);
		double tolerance = pow(0.1, num_decimal_places[i]);
		if(fabs(actual - est) > tolerance){
			printf("Square root tests: estimate for sqrt(%f) is not within tolerance %f\n", args[i], tolerance);
			NUM_FAILED_TESTS++;
		}
	}
}

int run_tests(){
	printf("*** Running ex02sqrt tests ***\n");
	test_sqrt();
	if(NUM_FAILED_TESTS == 0){
		printf("*** Finished ex02sqrt tests: all tests passed ***\n");
	} else {
		printf("*** Finished ex02sqrt tests: %d tests failed ***\n", NUM_FAILED_TESTS);
	}
	return NUM_FAILED_TESTS;
}
