#include <stdlib.h>
#include <stdio.h>

static int FIRST;
static int LAST;
static int INCREMENT;

void read_args(int argc, char *argv[]){
	if(argc == 2){
		FIRST = 1;
		INCREMENT = 1;
		LAST = atoi(argv[1]);	
	} else if(argc == 3){
		FIRST = atoi(argv[1]);
		INCREMENT = 1;
		LAST = atoi(argv[2]);
	} else if(argc == 4){
		FIRST = atoi(argv[1]);
		INCREMENT = atoi(argv[2]);
		LAST = atoi(argv[3]);
	}
}

// TODO: decreasing sequence
int main(int argc, char *argv[]){
	read_args(argc, argv);
	printf("First: %d\n", FIRST);
	printf("Last: %d\n", LAST);
	printf("Increment: %d\n", INCREMENT);
	int i;
	for(i = FIRST; i <= LAST; i = i + INCREMENT){
		printf("%d\n", i);
	}
	return 0;
}

