#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static char flag = 'K'; // default
static long long value;

// Holds sizes for K, M, G, T, P, E in that order
static unsigned long long format_sizes[] = {
	1024L, 1048576L, 1073741824L, 1099511627776L, 1125899906842624L, 1152921504606846976L
};

// Given the flag simply looks up the format size from the precalulcated array.
// Example: K = 1024, M = 1024*1024 and so on
unsigned long long get_size_from_flag(){
	switch(flag){
	case 'K':
		return format_sizes[0];
	case 'M':
		return format_sizes[1];
	case 'G':
		return format_sizes[2];
	case 'T':
		return format_sizes[3];
	case 'P':
		return format_sizes[4];
	case 'E':
		return format_sizes[5];
	default:
		printf("Unknown size flag: %c\n", flag);
		exit(1);
		break;
	}
}

// Given the input value we keep dividing it by 1024 until the result is less
// than 1024, this gives us the most convienient format to use.
static char find_cloest_size(){
	char sizes[] = { 'K', 'M', 'G', 'T', 'P', 'E' };
	int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
	unsigned long long val_copy = value;
	int i;
	for(i = 0; i < num_sizes; i++){
		val_copy = val_copy / 1024L;
		if(val_copy < 1024L){
			return sizes[i];
		}
	}
	return 'E';
}

// If no flag is passed the default of 'K' is used (set above).
// If flag is 'h' then the cloest matching size format is found.
void parse_args(int argc, char *argv[]){
	char c;
	while((c = getopt(argc, argv, "EPTGMKh")) != -1){
		flag = c;
	}
	value = atol(argv[optind]);
	if(flag == 'h'){
		flag = find_cloest_size();
	}
	
}

int main(int argc, char *argv[]){
	parse_args(argc, argv);
	unsigned long long size = get_size_from_flag();
	double result = (double) value / (double) size;
	printf("%llu = %.1f%c\n", value, result, flag);
	return 0;
}

