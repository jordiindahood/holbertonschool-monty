#include "monty.h"
/**
 * paaaarse- convert string to array of strings
 * @str: char *
 * Return: **char
 */
char **paaaarse(char *str)
{
	char *token, *delim = "\n", *tmp = NULL, **command = NULL;
	int count = 0, i = 0;

	if (!str)
		return (NULL);
	tmp = strdup(str);
	token = strtok(tmp, delim);

	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	command = (char **)malloc(sizeof(char *) * count);
	if (command == NULL)
	{
		free(str);
		perror("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(str, delim);
	command[i] = (char *)malloc(_strlen(token) + 1);
	if (command[i] == NULL)
	{
		free_dp(command), command = NULL;
		perror("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	command[i] = strdup(token);
	for (i = 1; i < count; i++)
	{
		token = strtok(NULL, delim);
		command[i] = (char *)malloc(_strlen(token) + 1);

		if (command[i] == NULL)
			perror("Memory allocation error\n"), exit(EXIT_FAILURE);
		command[i] = strdup(token);
	}
	free(str), str = NULL;
	return (command);
}
