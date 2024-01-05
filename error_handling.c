#include "monty.h"
bool check_arguments(int ac)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (false);
	}
	return (true);
}
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
