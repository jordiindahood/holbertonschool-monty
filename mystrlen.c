#include "monty.h"
/**
 * _strlen - same as strlen
 * @s: char*
 * Return: int
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
