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
					 "nop",
					 NULL};

	/*THIS FUNCTION ALLOWS ME TO SKIP THE NUMBERS*/
	y = count_digits_or_chars(script);
	if (y > 0)
		return (-1);
	if (y < 0)
	{
		for (i = 0; array[i]; i++)
			if (strncmp(script, array[i], strlen(array[i])) == 0)
				return (1);
		/**
		 *else if (array[i + 1] == NULL)
		 *{
		 *	ch = script[index];
		 *	fprintf(stderr, "L%d: unknown instruction %s\n", index - x, ch);
		 *	free_dp(script);
		 *	exit(EXIT_FAILURE);
		 *}
		 */
	}
	/*SUCCESS if all commands found*/
	return (0);
}
/**
 * run_the_script - execution
 * @script: char**
 * Return: void
 */
void run_the_script(char **script)
{
	char *ch;
	int state;
	stack_t *node = NULL;
	instruction_t commands[] = {{"push", pushf},
								{"pall", pallf},
								{"pint", pintf},
								{"pop", popf},
								{"swap", swapf},
								{"add", addf},
								{"nop", nopf},
								{NULL, NULL}};
	int i, index, x = 0;

	if (count_digits_or_chars(script[0]) > 0)
	{
		fprintf(stderr, "L1: unknown instruction %s\n", script[0]);
		free_dp(script), script = NULL, exit(EXIT_FAILURE);
	}
	for (index = 0; script[index]; index++)
	{
		state = check_for_functions(script[index]);
		if (state == -1)
			continue;
		if (state == 0)
		{
			ch = script[index];
			fprintf(stderr, "L%d: unknown instruction %s\n", index + 1, ch);
			free_dp(script);
			exit(EXIT_FAILURE);
		}
		for (i = 0; commands[i].opcode; i++)
		{
			if (strcmp(script[index], commands[0].opcode) == 0)
			{
				if (count_digits_or_chars(script[index + 1]) > -1)
				{
					index++;
					node = create_node(_atoi(script[index]));
					pushf(&node, index + 1 - x), x++;
				}
				else
				{
					fprintf(stderr, "L%d: usage: push integer\n", index - x + 1);
					free_dp(script), script = NULL, exit(EXIT_FAILURE);
				}
			}
			else if (strcmp(commands[i].opcode, script[index]) == 0)
				commands[i].f(&node, index + 1 - x);
		}
	}
	free_stack(node), node = NULL, free_dp(script), script = NULL;
}
