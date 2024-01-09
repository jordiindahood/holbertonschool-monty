#ifndef MONTY
#define MONTY
/*DOUUBLE INCLUSION PROTECTION*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

#define UNUSED(x) (void)(x) /*macro function similar to unused attribute*/
#define DELIM " $\n"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*error funcs*/
bool check_objc_file(char **);
bool check_arguments(int);

/*file ops*/
char *read_file(const char *);
char **paaaarse(char *);
void run_the_script(char **);

/*op functions*/
void pushf(stack_t **stack, unsigned int line_number);
void pallf(stack_t **stack, unsigned int line_number);
void pintf(stack_t **stack, unsigned int line_number);
void popf(stack_t **stack, unsigned int line_number);
void swapf(stack_t **stack, unsigned int line_number);
void addf(stack_t **stack, unsigned int line_number);
void nopf(stack_t **stack, unsigned int line_number);

/*my functions*/
void free_dp(char **);
int _atoi(char *);
int check_for_functions(char *);
int count_digits_or_chars(char *);
void free_stack(stack_t *head);
stack_t *create_node(int n);

#endif
