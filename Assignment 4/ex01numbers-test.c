#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions defined in ex01numbers.c that we want to test.

int is_square_number(int num);
int is_triangular_number(int num);

static int NUM_FAILED_TESTS = 0;

// Note: 0 is a square number since 0*0 = 0
// This test makes sure we are handling that correctly.
static void run_square_number_tests(){
	printf("Running square number tests\n");
	int args[] = { -1, 0, 9, 10, 16, 17, 100, 1000, 10000 };
	int expected[] = { 0, 1, 1, 0, 1, 0, 1, 0, 1 };
	int i;
	for(i = 0; i < sizeof(args) / sizeof(args[0]); i++){
		if(is_square_number(args[i]) != expected[i]){
			printf("Square number tests: incorrect result for %d\n", args[i]);
			NUM_FAILED_TESTS++;
		}
	}
	printf("Finished square number tests\n");
}

// Note: 0 is considered a triangular number (https://oeis.org/A000217).
// This test makes sure we are handling that correctly.
static void run_triangular_number_tests(){
	printf("Running triangular number tests\n");
	int args[] = { -1, 0, 1, 4, 10, 1035, 1036, 1431, 1432 };
	int expected[] = { 0, 1, 1, 0, 1, 1, 0, 1, 0 };
	int i;
	for(i = 0; i < sizeof(args) / sizeof(args[0]); i++){
		if(is_triangular_number(args[i]) != expected[i]){
			printf("Triangular number tests: incorrect result for %d\n", args[i]);
			NUM_FAILED_TESTS++;
		}
	}
	printf("Finished triangular number tests\n");
}

int run_tests(){
	printf("*** Running ex01numbers tests ***\n");
	run_square_number_tests();
	run_triangular_number_tests();
	if(NUM_FAILED_TESTS == 0){
		printf("*** Finished ex01numbers tests: all tests passed ***\n");
	} else {
		printf("*** Finished ex01numbers tests: %d tests failed ***\n", NUM_FAILED_TESTS);
	}
	return NUM_FAILED_TESTS;
}

