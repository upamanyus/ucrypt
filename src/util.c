#include "util.h"
#include <stdio.h>
#include <stdlib.h>

char *read_full_file(const char *filename)
{
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	size_t len = ftell(file);
	rewind(file);

	char *content = (char*)malloc(len + 1);
	size_t num_read = fread(content, len, 1, file);

	if (num_read != 1)
	{
		free(content);
		return NULL;
	}

	fclose(file);
	return content;
}
