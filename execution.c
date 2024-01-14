#include "monty.h"
/**
 * run_the_script - execution
 * @script: char**
 * Return: void
 */
int run_the_script(char *script, int line, FILE *file, stack_t **head)
{
	instruction_t commands[] = {{"push", pushf},
								{"pall", pallf},
								{"pint", pintf},
								{"pop", popf},
								{"swap", swapf},
								{"add", addf},
								{"nop", nopf},
								{NULL, NULL}};
	int i = 0;
	char *func;

	func = strtok(script, " $\n\t");
	if (func && func[0] == '#')
		return (0);
	global.arg = strtok(NULL, " $\n\t");
	while (commands[i].opcode && func)
	{
		if (strcmp(func, commands[i].opcode) == 0)
		{
			commands[i].f(head, line);
			return (0);
		}
		i++;
	}
	if (func && commands[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, func);
		fclose(file);
		free(script);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	return (1);
}
