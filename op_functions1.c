#include "monty.h"
stack_t *stk = NULL;
/**
 * pushf - push element to the stack
 * @node: stack**
 * @n: unsigned
 * Return: void
 */
void pushf(stack_t **node, unsigned int n)
{
	stack_t *tmp;

	UNUSED(n);
	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
	if (stk == NULL)
	{
		stk = *node;
		return;
	}
	tmp = stk;
	stk = *node;
	stk->next = tmp;
	tmp->prev = stk;
}
/**
 * pallf - print all elements of the stack
 * @stack: stack**
 * @line_number: unsigned
 * Return: void
 */
void pallf(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);

	tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pintf - print the value of top of the stack
 * @stack: stack**
 * @line_number: unsigned
 * Return: void
 */
void pintf(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (!stk)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	printf("%d\n", tmp->n);
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
