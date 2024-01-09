#include "monty.h"
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
