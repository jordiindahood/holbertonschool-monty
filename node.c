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
 * create_node - create a node and give it a value
 * @n: int
 * Return: stack_t *
 */
stack_t *create_node(int n)
{
	stack_t *node = (stack_t *)malloc(sizeof(stack_t *));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	return (node);
}
/**
 * free_stack - free list
 * @head: list *
 * Return: void
 */
void free_stack(stack_t *head)
{
	if (head)
	{
		free_stack(head->next);
		free(head);
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
