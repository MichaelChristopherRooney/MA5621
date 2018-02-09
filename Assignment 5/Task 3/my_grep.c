#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int invert = 0;
static int use_line_num = 0;
static int use_colour = 0;

void parse_args(int argc, char *argv[]){
	int c;
	while((c = getopt(argc, argv, "cnv")) != -1){
		switch(c){
		case 'c':
			use_colour = 1;
			break;
		case 'n':
			use_line_num = 1;
			break;
		case 'v':
			invert = 1;
			break;
		default:
			break;
		}
	}
}

// TODO: read from file
// TODO: colours
int main(int argc, char *argv[]){
	parse_args(argc, argv);
	size_t size = 256;
	char *buf = malloc(size);
	int line_num = 1;
	while(getline(&buf, &size, stdin) != -1){
		char *found = strstr(buf, "include");
		if((found != NULL && invert == 0) || (found == NULL && invert == 1)){
			if(use_line_num){
				printf("%d:", line_num);
			}
			printf("%s", buf);
		}
		line_num++;
	}
	return 0;
}

