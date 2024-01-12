#include "monty.h"
/**
 * main - entry point
 * @av: char**
 * @ac: int
 * Return: 0
 */
int main(int ac, char **av)
{
	char *str;
	char **script;

	/*Error: a monty file doesn't exist or hasn't met the required arguments*/
	if (!check_arguments(ac))
		exit(EXIT_FAILURE);

	/*READ*/
	str = read_file(av[1]);
	if (!str)
		return (EXIT_SUCCESS);
	/*PARSE*/
	script = paaaarse(str);

	/*EXECUTION*/
	run_the_script(script);

	return (EXIT_SUCCESS);
}
