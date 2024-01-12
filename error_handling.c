#include "monty.h"
/**
 * check_arguments - check if there is are 2 cases in av**
 * @ac: int
 * Return: true if exists, false otherwise
 */
bool check_arguments(int ac)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (false);
	}
	return (true);
}
