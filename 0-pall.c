#include "monty.h"

/**
 * _pall - Prints all values, starting from the topon the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number of the opcode in the script.
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	(void)line_number;

	if (curr == NULL)
	{
		return;
	}
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->prev;
	}
}
