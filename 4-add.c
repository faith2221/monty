#include "monty.h"

/**
 * _add - Adds the top two elements of the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number of the opcode in the script.
 * Return: Nothing.
 */

void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);
}
