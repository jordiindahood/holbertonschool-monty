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
/**
 * check_objc_file - see if the file to be executed has .m extension
 * @av: char**
 * Return: true if exists, false otherwise
 */
bool check_objc_file(char **av)
{
	int num = strlen(av[1]);

	if (!(av[1][num - 2] == '.' && av[1][num - 1] == 'm'))
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (false);
	}
	return (true);
}
