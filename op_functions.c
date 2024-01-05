#include "monty.h"
void pushf(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	printf("i just used push\n");
}
void pallf(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	printf("i just used pall in line %d\n", line_number);
}
void pintf(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	printf("i just used pint in line %d\n", line_number);
}
void popf(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	printf("i just used pop in line %d\n", line_number);
}
void swapf(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	printf("i just used swap in line %d\n", line_number);
}
void addf(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	printf("i just used add in line %d\n", line_number);
}
void nopf(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	printf("i just used nop in line %d\n", line_number);
}
