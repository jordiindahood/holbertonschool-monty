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
	char *tekst = NULL;

	file = fopen(filename, "r");
	n = getline(&buf, &len, file);
	if (n == -1)
	{
		free(buf), buf = NULL;
		return (NULL);
	}
	tekst = malloc(strlen(buf)+1);
	strcpy(tekst, buf);

	free(buf), buf = NULL;

	while (getline(&buf, &len, file) != -1)
	{
		tekst = realloc(tekst, len);
		strcat(tekst, buf);
		free(buf), buf = NULL;
	}
	fclose(file);
	return (tekst);
}
