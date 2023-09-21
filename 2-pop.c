#include "monty.h"

/**
 * _pop - Removes the top element of the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number of the opcode in the script.
 * Return: Nothing.
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		print_popError(line_number);
		exit(EXIT_FAILURE);
	}

	_popTop(stack);
}

/**
 * _popTop - Removes the top element.
 * @stack: The pointer to the stack.
 */

void _popTop(stack_t **stack)
{
	stack_t *tmp = *stack;

	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_popError - Prints the error message for popping an empty stack.
 * @line_number: The line number of the opcode in the script.
 */

void print_popError(unsigned int line_number)
{
	fprintf(stderr, "l%u: can't pop an empty stack\n", line_number);
}
