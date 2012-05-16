#include <stdio.h>
#include <stdlib.h>

#include "svmletters.h"

int main()
{
	int x;
	while(scanf("%d", &x) == 1)
		printf("%c\n", value_letter(x));
	return 0;
}
