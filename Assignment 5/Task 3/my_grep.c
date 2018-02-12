#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int INVERT_SEARCH = 0;
static int PRINT_LINE_NUM = 0;
static int USE_COLOUR = 0;

static char *SEARCH_WORD = "include";
static int SEARCH_WORD_LEN;

#define COLOUR_RED "\x1B[31m"
#define COLOUR_GREEN "\x1B[32m"
#define COLOUR_RESET "\x1B[0m"

static void parse_args(int argc, char *argv[]){
	int c;
	while((c = getopt(argc, argv, "cnv")) != -1){
		switch(c){
		case 'c':
			USE_COLOUR = 1;
			break;
		case 'n':
			PRINT_LINE_NUM = 1;
			break;
		case 'v':
			INVERT_SEARCH = 1;
			break;
		default:
			break;
		}
	}
	if(argc - optind != 1){
		printf("ERROR: please provide a word to search for\n");
		exit(1);
	}
	SEARCH_WORD = argv[optind];
}

// Iterates over the string. Prints the search word in red if it's found.
// Otherwise prints with the default colour.
// Because i may increment either by 1 or the word lenght I use a while
// loop instead of a for loop
// Note: strncmp is used over strcmp since we need to specify a max length.
// Without the max length strcmp will fail often since the search word in the line
// does not have a matching null terminator.
static void print_line(char *line, int line_num){
	if(PRINT_LINE_NUM){
		printf(COLOUR_GREEN);
		printf("%d:", line_num);
		printf(COLOUR_RESET);
	}
	if(INVERT_SEARCH == 1 || USE_COLOUR == 0){ // just print the line, no highlighting
		printf("%s", line);
		return;
	}
	int line_len = strlen(line);
	int i = 0;
	while(i < line_len){
		if(strncmp(line + i, SEARCH_WORD, SEARCH_WORD_LEN) == 0){
			printf(COLOUR_RED);
			printf("%.*s", SEARCH_WORD_LEN, line + i);
			printf(COLOUR_RESET);
			i = i + SEARCH_WORD_LEN;
		} else {
			printf("%c", line[i]);
			i++;
		}
	}
}

// TODO: read from file
int main(int argc, char *argv[]){
	parse_args(argc, argv);
	SEARCH_WORD_LEN = strlen(SEARCH_WORD);
	size_t size = 256;
	char *line = malloc(size);
	int line_num = 1;
	while(getline(&line, &size, stdin) != -1){
		char *found = strstr(line, SEARCH_WORD);
		if((found != NULL && INVERT_SEARCH == 0) || (found == NULL && INVERT_SEARCH == 1)){
			print_line(line, line_num);
		}
		line_num++;
	}
	return 0;
}

