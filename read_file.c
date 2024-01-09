#include "monty.h"
/**
 * read_file - read a file
 * @filename: const char *
 * Return: char*
 */
char *read_file(const char *filename)
{
	FILE *file;
	ssize_t n;
	size_t len = 0;
	char *buf = NULL;
	char *tmp = NULL, *tekst = NULL;

	file = fopen(filename, "r");
	n = getline(&buf, &len, file);
	if (n == -1)
	{
		fprintf(stderr, "Error: Can't open file %s", filename);
		free(buf), buf = NULL;
		exit(EXIT_FAILURE);
	}
	tekst = malloc(strlen(buf) + 1);
	strcpy(tekst, buf);
	free(buf), buf = NULL;

	while (getline(&buf, &len, file) != -1)
	{
		/*thanks to the checker, they dont want me to use realloc -_-*/
		tmp = strdup(tekst);
		free(tekst), tekst = NULL;
		tekst = malloc(sizeof(tmp) + len);
		strcpy(tekst, tmp);
		free(tmp), tmp = NULL;
		strcat(tekst, buf);
		free(buf), buf = NULL;
	}
	fclose(file);
	return (tekst);
}
