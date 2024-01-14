#include "monty.h"
/**
 * pushf - push element to the stack
 * @node: stack**
 * @n: unsigned
 * Return: void
 */
void pushf(stack_t **head, unsigned int line)
{
	int n;
	stack_t *node;

	if (global.arg == NULL || count_digits_or_chars(global.arg) < 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		fclose(global.file);
		free(global.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = _atoi(global.arg);
	node = create_node(n);

	if (*head == NULL)
	{
		*head = node;
		return;
	}
	node->next = (*head);
	(*head)->prev = node;
	*head = node;
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
	node->next = NULL;
	node->prev = NULL;

	return (node);
}
/**
 * free_stack - free list
 * @head: list *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
/**
 * pintf - print the value of top of the stack
 * @stack: stack**
 * @line_number: unsigned
 * Return: void
 */
void pintf(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (!head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
		exit(EXIT_FAILURE);
	tmp = *head;
	printf("%d\n", tmp->n);
}
