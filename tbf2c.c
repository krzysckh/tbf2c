#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	if (argv[1] == NULL) {
		fp = stdin;
	} else {
		fp = fopen(argv[1], "r");
	}
	if (fp == NULL) {
		printf("%s %s\n", "error: cannot open file: ", argv[1]);
		return 1;
	}
	printf("#include <stdio.h>\nint tp[30000];\nint ptr = 0;\nint main() {\n");
	char c;
	while (c != EOF) {
		c = fgetc(fp);
		switch (c) {
			case '>':
				printf("ptr++;\n");
				break;
			case '<':
				printf("ptr--;\n");
				break;
			case '+':
				printf("tp[ptr]++;\n");
				break;
			case '-':
				printf("tp[ptr]--;\n");
				break;
			case '.':
				printf("putchar(tp[ptr]);\n");
				break;
			case ',':
				printf("tp[ptr] = getchar();\n");
				break;
			case '[':
				printf("while (tp[ptr] != 0) {\n");
				break;
			case ']':
				printf("}\n");
				break;
		}
	}
	printf("}");
	
	fclose(fp);
	return 0;
}	
