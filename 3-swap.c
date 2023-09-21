#include "monty.h"

/**
 * _swap - Swaps the top two elements of the stack.
 * @stack: The pointer to the stack.
 * @line_number: The line number of the opcode in the script.
 * Return: Nothing.
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *firstNode, *secondNode;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	firstNode = *stack;
	secondNode = firstNode->next;

	firstNode->next = secondNode->next;
	if (secondNode->next != NULL)
		secondNode->next->prev = firstNode;

	secondNode->prev = NULL;
	secondNode->next = firstNode;
	firstNode->prev = secondNode;

	*stack = secondNode;
}
