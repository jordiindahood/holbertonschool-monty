#include "monty.h"
/**
 * pushf - push element to the stack
 * @head: stack**
 * @line: unsigned
 * Return: void
 */
void pushf(stack_t **head, unsigned int line)
{
	int n;
	stack_t *node;
	char *arg;

	arg = strtok(global.arg, " \n\t$");

	if (arg == NULL || count_digits_or_chars(global.arg) < 1)
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
 * @head: stack**
 * @line_number: unsigned
 * Return: void
 */
void pintf(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(global.file), free(global.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
