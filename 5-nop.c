#include "monty.h"

/**
 * _nop - Does not perform any operation.
 * @stack: The pointer to the stack.
 * @line_number: The line number of the opcode in the script.
 * Return: Nothing.
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
