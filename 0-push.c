#include "monty.h"

/**
 * _push - Pushes an int argument onto a stack.
 * @stack: The pointer.
 * @line_number: Unsigned int representing curr line num.
 * Return: Nothing.
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;
	stack_t *newNode;

	arg = strtok(NULL, "\t\n\r");
	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = n;
	newNode->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = newNode;
	}
	newNode->next = *stack;
	*stack = newNode;

	var.stack_len++;
}

/**
 * is_valid - Checks if string represents a valid integer.
 * @str: The pointer to a character string.
 * Return: 1 if the string is valid , otherwise 0.
 */

int is_valid(const char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
	{
		return (0);
	}
	if (str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
