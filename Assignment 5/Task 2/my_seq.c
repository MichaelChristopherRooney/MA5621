#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static unsigned long long FIRST = 1; // default
static unsigned long long INCREMENT = 1; // default
static unsigned long long LAST;

static int USE_PADDING = 0;
static char PADDING_FMT[9] = "%000llu\n"; // second and third zero will be overwritten

// Only option that getopt can handle is -w
// If FIRST or INCREMENT are not passed they will have the default value set above.
static void read_args(int argc, char *argv[]){
	char c;
	while((c = getopt(argc, argv, "w")) != -1){
		USE_PADDING = 1;
	}
	int offset = optind - 1;
	switch((argc - optind) + 1){
	case 2:
		LAST = atol(argv[1 + offset]);
		break;
	case 3:
		FIRST = atol(argv[1 + offset]);
		LAST = atol(argv[2 + offset]);
		break;
	case 4:
		FIRST = atol(argv[1 + offset]);
		INCREMENT = atol(argv[2 + offset]);
		LAST = atol(argv[3 + offset]);
		break;
	default:
		printf("Bad args passed\n");
		exit(1);
	}
}

// TODO: if LAST will not be reached then use LAST - INCREMENT as size
// The amount of zero padding depends on the value of LAST.
// First figure out how many chars LAST needs as a string.
// This is the padding size.
// We then turn the pad size into a string so it can be copied to the format.
// With this we can then create the format needed to zero pad.
// Example: last = 1000 -> needs 4 chars -> format = %llu004
// Example: last = 10^10 -> needs 11 chars -> format = %llu011
// Note: leading 0 in format is needed for zero padding when pad size > 9
static void set_padding_format(){
	char buf[21]; // should hold up to 2^64 as a string
	sprintf(buf, "%llu", LAST);
	int pad_num_chars = strlen(buf);
	sprintf(buf, "%d", pad_num_chars);
	if(pad_num_chars > 9){ // if pad size needs two characters in format
		PADDING_FMT[2] = buf[0];
		PADDING_FMT[3] = buf[1];
	} else { // if pad size needs one character in format
		PADDING_FMT[2] = '0';
		PADDING_FMT[3] = buf[0];
	}
}

int main(int argc, char *argv[]){
	read_args(argc, argv);
	if(USE_PADDING){
		set_padding_format();
	}
	unsigned long long i;
	for(i = FIRST; i <= LAST; i = i + INCREMENT){
		if(USE_PADDING){
			printf(PADDING_FMT, i);
		} else {
			printf("%llu\n", i);
		}
	}
	return 0;
}

