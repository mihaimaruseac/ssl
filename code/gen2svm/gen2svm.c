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
	int i, j;
	char **matrix, **tmatrix;
	int LINES, COLUMNS, TLINES, TCOLUMNS;

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

	trim_img(matrix, &tmatrix, LINES, COLUMNS, &TLINES, &TCOLUMNS);

	for (i = 0; i < LINES; i++)
		for (j = 0; j < COLUMNS; j++)
			if (matrix[i][j])
				printf(" %d:%d", 100000 * i + j, i + j + matrix[i][j]);

	printf("\n");

	for (i = 0; i < LINES; i++)
		free(matrix[i]);
	free(matrix);
	for (i = 0; i < TLINES; i++)
		free(tmatrix[i]);
	free(tmatrix);

	return 0;
}
