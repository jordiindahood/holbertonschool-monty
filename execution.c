#include "monty.h"
/**
 * check_for_functions - see if the script has no unknown functions
 * @script: char**
 * Return: 1 ON SUCCESS, 0 ON FAIL
 */
int check_for_functions(char *script)
{
	int i = 0, y;
	char *array[] = {"push",
					 "pall",
					 "pint",
					 "pop",
					 "swap",
					 "add",
					 "nop"};

	script = strtok(script, " \n\t");
	if (!script)
		return (-2);
	y = count_digits_or_chars(script);
	if (y < 0)
	{
		for (i = 0; array[i]; i++)
			if (strcmp(script, array[i]) == 0)
				return (i);
	}
	return (-1);
}
/**
 * run_the_script - execution
 * @script: char**
 * Return: void
 */
void run_the_script(char **script)
{
	int state;
	stack_t *node;
	instruction_t commands[] = {{"push", pushf},
								{"pall", pallf},
								{"pint", pintf},
								{"pop", popf},
								{"swap", swapf},
								{"add", addf},
								{"nop", nopf}};
	int i = 0;
	char *func, *value;

	for (i = 0; script[i]; i++)
	{
		func = strtok(script[i], " \n");
		if (strcmp(script[i], "push") == 0)
			value = strtok(NULL, " \n$");
		state = check_for_functions(func);
		if (state == -1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", i + 1, func);
			free_stack(node), node = NULL, free_dp(script), script = NULL;
			exit(EXIT_FAILURE);
		}
		if (strncmp(func, commands[0].opcode, 4) == 0)
		{
			if (count_digits_or_chars(value) < 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", i + 1);
				free_stack(node), node = NULL, free_dp(script), script = NULL;
				exit(EXIT_FAILURE);
			}
			node = create_node(_atoi(value));
			pushf(&node, i + 1);
		}
		else
			commands[state].f(&node, i + 1);
	}
	free_stack(node), node = NULL, free_dp(script), script = NULL;
}
