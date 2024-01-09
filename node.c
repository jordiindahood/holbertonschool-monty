#include "monty.h"
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
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
