#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 0x10
static char BUFFER[BLOCK_SIZE];
static const char REPLACE[] = {
	'\0', '\a', '\b', '\f', '\n', '\r', '\t', '\v'
};

static int char_needs_replacement(char c){
	int i;
	for(i = 0; i < sizeof(REPLACE) / sizeof(REPLACE[0]); i++){
		if(REPLACE[i] == c){
			return 1;
		}
	}
	return 0;
}

static void pad_with_spaces(int size){
	int n;
	for(n = size; n < BLOCK_SIZE; n++){
		printf("   ");
	}
}

static void print_char_part(int size){
	if(size < BLOCK_SIZE){
		pad_with_spaces();
	}
	printf("|");
	int i;
	for(i = 0; i < size; i++){
		if(char_needs_replacement(BUFFER[i]) == 1){
			printf(".");
		} else {
			printf("%c", BUFFER[i]);
		}
	}
	printf("|");
}

int main(int argc, char *argv[]){
	int line_num = 0;
	int cur_line_size = 0;
	int cur_char = 0;
	int finished = 0;
	while(!finished){
		printf("%08x  ", line_num * BLOCK_SIZE);
		cur_line_size = 0;
		int i;
		for(i = 0; i < BLOCK_SIZE; i++){
			cur_char = fgetc(stdin);
			cur_line_size++;
			if(cur_char == EOF){
				finished = 1;
				cur_line_size = i;
				break;
			}
			BUFFER[i] = cur_char;
			if(i == ((BLOCK_SIZE / 2) - 1) || i == BLOCK_SIZE - 1){
				printf("%02x  ", cur_char);
			} else {
				printf("%02x ", cur_char);
			}
		}
		print_char_part(cur_line_size);
		line_num++;
		printf("\n");
	}
	printf("%08x\n", ((line_num -1) * BLOCK_SIZE) + cur_line_size);
}

