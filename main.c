#include "monty.h"
/**
 * main - entry point
 * @av: char**
 * @ac: int
 * Return: 0
 */
int main(int ac, char **av)
{
	/*Error: a monty file doesn't exist or hasn't met the required arguments*/
	if (!check_arguments(ac))
		exit(EXIT_FAILURE);

	/*START EXECUTION*/
	read_file(av[1]);

	return (EXIT_SUCCESS);
}
