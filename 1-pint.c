#include "monty.h"

/**
 * _pint - Prints the value at the top of the stack, followed by a newline.
 * @stack: The pointer to the stack;
 * @line_number: The line number of the opcode in the script.
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *topNode;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	topNode = *stack;

	printf("%d\n", topNode->n);
}
