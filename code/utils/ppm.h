#ifndef PPM_H
#define PPM_H

#define LINE 1024

/* statically defined as an hack */
static char **read_P1_img(FILE *f, int *LINES, int *COLUMNS)
{
	int i, j;
	char c, line[LINE];
	char **matrix = NULL;

	/* read P1 */
	if (!fgets(line, LINE, f))
		goto err;
	if (line[0] != 'P' || line[1] != '1')
		goto err;

	/* read size */
	if (!fgets(line, LINE, f))
		goto err;
	if (sscanf(line, "%d%d", COLUMNS, LINES) != 2)
		goto err;

	matrix = calloc(*LINES, sizeof(matrix[0]));
	for (i = 0; i < *LINES; i++) {
		matrix[i] = calloc(*COLUMNS, sizeof(matrix[0][0]));
		for (j = 0; j < *COLUMNS; j++) {
			fscanf(f, "%c", &c);
			switch (c) {
			case '0': matrix[i][j] = 0; break;
			case '1': matrix[i][j] = 1; break;
			case '\n': /* ignore */
			case ' ':
			case '\r': j--; break; /* same */
			default: goto err;
			}
		}
	}
	return matrix;
err:
	return NULL;
}

#endif

