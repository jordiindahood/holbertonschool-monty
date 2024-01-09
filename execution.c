#include "monty.h"
/**
 * check_for_functions - see if the script has no unknown functions
 * @script: char**
 * Return: -1
 */
int check_for_functions(char **script)
{
	int i = 0, y, x = 0, index = 0;
	char *ch;
	char *array[] = {"push",
					 "pall",
					 "pint",
					 "pop",
					 "swap",
					 "add",
					 "nop",
					 NULL};

	for (index = 0; script[index]; index++)
	{
		/*THIS FUNCTION ALLOWS ME TO SKIP THE NUMBERS*/
		/*(strings that has BOTH nums and chars are allowed)*/
		y = count_digits_or_chars(script[index]);
		if (y > 0)
			x++;
		if (y < 1)
		{
			/*NOTE: edit here if there is a necessity to output an error in case of*/
			/*two consecutive cases of array that contains only integers*/
			/*------------------------------------*/
			/*trying to find the command in the array.*/
			/*if it doesnt exist, return its position*/
			for (i = 0; array[i]; i++)
				if (strncmp(script[index], array[i], strlen(array[i])) == 0)
					break;
				else if (array[i + 1] == NULL)
				{
					/*error at some line*/
					ch = script[index];
					fprintf(stderr, "L%d: unknown instruction %s\n", index - x, ch);
					free_dp(script);
					exit(EXIT_FAILURE);
				}
		}
	}
	/*SUCCESS if all commands found*/
	return (-1);
}
/**
 * run_the_script - execution
 * @script: char**
 * Return: void
 */
void run_the_script(char **script)
{
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
	free_stack(node), node = NULL;
	free_dp(script), script = NULL;
}
