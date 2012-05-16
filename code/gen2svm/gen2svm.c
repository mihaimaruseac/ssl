#include <stdio.h>
#include <stdlib.h>

#include "svmletters.h"

#define LINES 25
#define COLUMNS 30

void usage(char *pname)
{
	fprintf(stderr, "Usage:\n");
	fprintf(stderr, "\t%s LETTERFILE IMGFILE\n", pname);
	exit(EXIT_FAILURE);
}

int main(int argc, char** argv)
{
	FILE *f;
	char line[COLUMNS + 2];
	int i, j, s;
	unsigned char matrix[LINES][COLUMNS];

	if (argc != 3)
		usage(argv[0]);

	f = fopen(argv[1], "r");
	if (!f)
		usage(argv[0]);

	if (!fgets(line, COLUMNS, f))
		usage(argv[0]);

	printf("%d", letter_value(line[0]));
	
	fclose(f);

	f = fopen(argv[2], "r");
	if (!f)
		usage(argv[0]);

	for (i = 0; i < LINES; i++) {
		if (!fgets(line, COLUMNS + 2, f))
			usage(argv[0]);

		for (j = 0; j < COLUMNS; j++)
			switch (line[j]) {
			case '0': matrix[i][j] = 0; break;
			case '1': matrix[i][j] = 1; break;
			default: usage(argv[0]);
			}
	}

#if 0
	for (j = 0; j < COLUMNS; j++) {
		s = 0;
		for (i = 0; i < LINES; i++)
			s += matrix[i][j];
		if (s)
			printf(" %d:%d", j, s);
	}
#endif

	for (i = 0; i < LINES; i++) {
#if 0
		s = 0;
#endif
		for (j = 0; j < COLUMNS; j++)
			if (matrix[i][j])
				printf(" %d:%d", 1000 * i + j, matrix[i][j]);
#if 0
			s += matrix[i][j];
		if (s)
			printf(" %d:%d", 1000 + i, s);
#endif
	}

	printf("\n");

	fclose(f);
	return 0;
}
