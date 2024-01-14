#include "monty.h"
data_t global = {NULL, NULL, NULL};
/**
 * read_file - read a file
 * @filename: const char *
 * Return: char*
 */
int *read_file(const char *filename)
{
	FILE *file;
	ssize_t n = 1;
	size_t len = 0;
	stack_t *head = NULL;
	int line = 0;
	char *buf = NULL;

	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	global.file = file;
	while (n > 0)
	{
		buf = NULL;
		n = getline(&buf, &len, file);
		global.content = buf;
		line++;
		if (n > 0)
			run_the_script(buf, line, file, &head);
		free(buf);
	}
	free_stack(head);
	fclose(file);
	return (EXIT_SUCCESS);
}
