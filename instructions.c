#include "monty.h"

/**
 * my_instruction - Checks instructions against valid opcodes.
 * @opd: Opcode to check.
 * @stack: The double pointer at the beginning of the stack.
 * @line_number: The script line number.
 * Return: Nothing.
 */

void my_instruction(char *opd, stack_t **stack, unsigned int line_number)
{
	size_t i = 0;
	instruction_t valid_opd[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	for (i = 0; valid_opd[i].opcode != NULL; i++)
	{
		if (strcmp(valid_opd[i].opcode, opd) == 0)
		{
			valid_opd[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opd);
	exit(EXIT_FAILURE);
}
