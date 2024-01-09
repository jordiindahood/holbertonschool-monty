#include "monty.h"
/**
 * swapf - swap the two first elements of the stack
 * @stack: stack**
 * @line_number: unsigned
 * Return: void
 */
void swapf(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
/**
 * addf - add the top two elements of the stack
 * @stack: stack**
 * @line_number: unsigned
 * Return: void
 */
void addf(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * nopf - do nothing
 * @stack: stack**
 * @line_number: unsigned
 * Return: void
 */
void nopf(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}
