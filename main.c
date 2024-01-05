#include "monty.h"
int main(int ac, char **av)
{
	char *str;
	char **script;

	/*Error: a monty file doesn't exist or hasn't met the required arguments*/
	if (!check_arguments(ac) || !check_objc_file(av))
		exit(EXIT_FAILURE);

	/*READ*/
	str = read_file(av[1]);
	/*PARSE*/
	script = paaaarse(str);

	/*pre-execution*/
	check_for_functions(script);

	/*EXECUTION*/
	run_the_script(script);
	/*FREEDOM IS RIGHT FOR EVERYONE, EVEN FOR POINTERS!!!*/
	if (script)
		free_dp(script), script = NULL;
	return (EXIT_SUCCESS);
}
