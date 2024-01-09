#include "monty.h"
/**
 * paaaarse- convert string to array of strings
 * @str: char *
 * Return: **char
 */
char **paaaarse(char *str)
{
	char *token, *delim = DELIM, *tmp = NULL, **command = NULL;
	int count = 0, i = 0;

	if (!str)
		return (NULL);
	tmp = strdup(str);
	token = strtok(tmp, delim);
	if (token == NULL)
	{
		free(str), str = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(tmp), tmp = NULL;
	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		free(str), str = NULL;
		return (NULL);
	}

	token = strtok(str, delim);
	while (token)
	{
		command[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	free(str), str = NULL;
	command[i] = NULL;
	return (command);
}
