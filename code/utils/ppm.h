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

static void trim_img(char **img, char ***timg, int L, int C, int *LINES, int *COLUMNS)
{
	int i, j, minl, maxl, minc, maxc, found;

	found = 0; /* trim top */
	for (i = 0; i < L && !found; i++)
		for (j = 0; j < C; j++)
			if(img[i][j] != 0) {
				found = 1;
				minl = i;
				break;
			}

	found = 0; /* trim bottom */
	for (i = L - 1; i >= 0 && !found; i--)
		for (j = 0; j < C; j++)
			if(img[i][j] != 0) {
				found = 1;
				maxl = i + 1;
				break;
			}

	found = 0; /* trim left */
	for (j = 0; j < C && !found; j++)
		for (i = 0; i < L; i++)
			if(img[i][j] != 0) {
				found = 1;
				minc = j;
				break;
			}

	found = 0; /* trim right */
	for (j = C - 1; j >= 0 && !found; j--)
		for (i = 0; i < L; i++)
			if(img[i][j] != 0) {
				found = 1;
				maxc = j + 1;
				break;
			}

	*LINES = maxl - minl;
	*COLUMNS = maxc - minc;
	*timg = calloc(*LINES, sizeof(img[0]));
	for (i = 0; i < *LINES; i++) {
		(*timg)[i] = calloc(*COLUMNS, sizeof(img[0][0]));
		for (j = 0; j < *COLUMNS; j++)
			(*timg)[i][j] = img[i + minl][j + minc];
	}
}

#endif

