#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Note: loop termination condition is empty.
// If i*i is > num it returns as num cannot possibly be a square number.
// This is done within the loop to avoid recalulcating i*i in the termination
// condition.
int is_square_number(int num){
	int i;
	for(i = 0; ; i++){	
		int sqr = i*i;
		if(sqr > num){
			return 0;
		}
		if(i * i == num){
			return 1;
		}
	}
	return 0;
}

// >= condition in the loop is used for when num == 0, as 0 is a triangular number.
int is_triangular_number(int num){
	int cur = 0;
	int i;
	for(i = 0; num >= cur; i++){
		cur = cur + i;
		if(num == cur){
			return 1;
		}
	}
	return 0;
}

// Defined in ex01numbers-test.c
int run_tests();

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Please provide a single integer arg, or 'test' if running tests\n");
		return 1;
	}
	if(strcmp(argv[1], "test") == 0){
		int result = run_tests();
		return result;
	}
	int n = atoi(argv[1]);
	int i;
	for(i = 1; i <= n; i++){
		int t = is_triangular_number(i);
		if(t != 0){
			printf("%d is triangular number\n", i);
		}
		t = is_square_number(i);
		if(t != 0){
			printf("%d is a square number\n", i);
		}
	}
	return 0;
}
