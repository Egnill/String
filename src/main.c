#include <stdio.h>
#include <stdlib.h>
#include "Work.h"

int main()
{
	char *s = malloc(MAX_PATH * sizeof(char));

	process(s);

	free(s);
	
	return 0;
}