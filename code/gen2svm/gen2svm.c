#include <stdio.h>
#include <stdlib.h>

#include "svmletters.h"
#include "ppm.h"

void usage(char *pname, char *msg)
{
	if (msg)
		fprintf(stderr, "%s\n", msg);
	fprintf(stderr, "Usage:\n");
	fprintf(stderr, "\t%s LETTERFILE IMGFILE\n", pname);
	exit(EXIT_FAILURE);
}

int main(int argc, char** argv)
{
	FILE *f;
	char line[LINE];
	int i, j, s;
	char **matrix;
	int LINES, COLUMNS;

	if (argc != 3)
		usage(argv[0], NULL);

	/* read letter */
	f = fopen(argv[1], "r");
	if (!f)
		usage(argv[0], "Invalid letter file");
	if (!fgets(line, LINE, f))
		usage(argv[0], "Invalid letter file");
	printf("%d", letter_value(line[0]));
	
	fclose(f);

	/* read CAPTCHA */
	f = fopen(argv[2], "r");
	if (!f)
		usage(argv[0], "Invalid CAPTCHA file");
	matrix = read_P1_img(f, &LINES, &COLUMNS);
	if (!matrix)
		usage(argv[0], "Invalid CAPTCHA file");
	fclose(f);

	for (j = 0; j < COLUMNS; j++) {
		s = 0;
		for (i = 0; i < LINES; i++)
			s += matrix[i][j];
		if (s)
			printf(" %d:%d", j, s);
	}

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

	for (i = 0; i < LINES; i++)
		free(matrix[i]);
	free(matrix);

	return 0;
}
