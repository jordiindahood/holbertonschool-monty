#include "monty.h"
/**
 * pallf - print all elements of the stack
 * @stack: stack**
 * @line_number: unsigned
 * Return: void
 */
void pallf(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	UNUSED(line_number);
	tmp = *stack;
	if (tmp == NULL)
		return;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * popf - remove the top node of the stack
 * @stack: stack**
 * @line_number: unsigned
 * Return: void
 */
void popf(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
