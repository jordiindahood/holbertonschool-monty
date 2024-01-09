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
	if (!check_arguments(ac) || !check_objc_file(av) || !av[1])
		exit(EXIT_FAILURE);

	/*READ*/
	str = read_file(av[1]);

	/*PARSE*/
	script = paaaarse(str);

	/*EXECUTION*/
	run_the_script(script);

	return (EXIT_SUCCESS);
}
