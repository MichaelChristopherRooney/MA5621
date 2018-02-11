#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 0x10
static char BUFFER[BLOCK_SIZE];
static const char REPLACE[] = {
	'\0', '\a', '\b', '\f', '\n', '\r', '\t', '\v'
};

// Checks if the character is in the REPLACE array defined above.
static int char_needs_replacement(char c){
	int i;
	for(i = 0; i < sizeof(REPLACE) / sizeof(REPLACE[0]); i++){
		if(REPLACE[i] == c){
			return 1;
		}
	}
	return 0;
}

// Used only for the final block to be printed.
// Pads the string part so that it is aligned with previous ones.
// The padding here depends on how spaces are printed in other parts of the code.
// Each byte printed uses 3 characters, so we can use this to figure out how
// many padding spaces are needed.
// Note: if size is < 5 we need to account for the extra dividing space on the
// 5th byte to be printed.
static void pad_with_spaces(int size){
	int num_spaces = ((BLOCK_SIZE - size) * 3) + 1;
	if(size < BLOCK_SIZE / 2){
		num_spaces += 1;
	}
	int n;
	for(n = 0; n < num_spaces; n++){
		printf(" ");
	}
}

// Prints the part at the end of the line enclosed in "|"
static void print_char_part(int size){
	if(size < BLOCK_SIZE){
		pad_with_spaces(size);
	}
	printf("|");
	int i;
	for(i = 0; i < BLOCK_SIZE; i++){
		if(char_needs_replacement(BUFFER[i]) == 1){
			printf(".");
		} else {
			printf("%c", BUFFER[i]);
		}
	}
	printf("|");
}

static int process_block_bytes(){
	int cur_char = 0;
	int cur_line_size = 0;
	int i;
	for(i = 0; i < BLOCK_SIZE; i++){
		cur_char = fgetc(stdin);
		cur_line_size++;
		if(cur_char == EOF){
			return i;
		}
		BUFFER[i] = cur_char;
		if(i == ((BLOCK_SIZE / 2) - 1) || i == BLOCK_SIZE - 1){
			printf("%02x  ", cur_char);
		} else {
			printf("%02x ", cur_char);
		}
	}
	return BLOCK_SIZE;
}

int main(int argc, char *argv[]){
	int line_num = 0;
	int cur_line_size = 0;
	int finished = 0;
	while(!finished){
		printf("%08x  ", line_num * BLOCK_SIZE);
		cur_line_size = process_block_bytes();
		if(cur_line_size < BLOCK_SIZE){
			finished = 1;
		}
		print_char_part(cur_line_size);
		line_num++;
		printf("\n");
	}
	printf("%08x\n", ((line_num - 1) * BLOCK_SIZE) + cur_line_size);
}

