#include <stdlib.h>
#include <stdio.h>

static char flag;
static long long value;

// TODO: other sizes
unsigned long long get_size_from_flag(){
	switch(flag){
	case 'K':
		return 1000l;
	case 'M':
		return 1000000l;
	break;
	}
}

void read_args(int argc, char *argv[]){
	if(argc == 3){
		flag = argv[1][1];
		value = atol(argv[2]);
	} else {
		flag = 'K'; // default
		value = atol(argv[1]);
	}
}

// TODO: move away from using double and division
int main(int argc, char *argv[]){
	read_args(argc, argv);
	unsigned long long size = get_size_from_flag();
	double result = (double) value / (double) size;
	printf("Flag is %c\n", flag);
	printf("Value is %llu\n", value);
	printf("Size is %llu\n", size);
	printf("Num is %f\n", result);
	return 0;
}

