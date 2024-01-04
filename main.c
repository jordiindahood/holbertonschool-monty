#include "monty.h"
int main(int ac, char **av)
{
	int i = 0;
	char *str;
	char **script;

	/*Error: a monty file doesn't exist or hasn't met the required arguments*/
	if (!check_arguments(ac) || !check_objc_file(av))
		exit(EXIT_FAILURE);

	/*READ*/
	str = read_file(av[1]);

	/*PARSE*/
	script = paaaarse(str);

	/*TESTINGGGGG*/
	while (script[i])
	{
		printf("----[%s]--{%d}--\n", script[i], i);
		i++;
	}
	/*EXECUTION*/

	/*FREEDOM IS RIGHT FOR EVERYONE, EVEN FOR POINTERS!!!*/
	free_dp(script);
	return (EXIT_SUCCESS);
}
