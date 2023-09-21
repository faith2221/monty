#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

var_t var = {0};

/**
 * main - The entry point.
 * @argc: Count of command-line arguments.
 * @argv: The array of argument strings.
 * Return: EXIT_SUCCESS on Success(0),
 * or EXIT_FAILURE on failur(1).
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int  line_number = 0;
	char *line = NULL;
	size_t line_len = 0;
	char *opd;
	stack_t *temp = stack;
	FILE *inputFile;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		return (EXIT_FAILURE);
	}
	inputFile = fopen(argv[1], "r");

	if (inputFile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line, line_len, inputFile) != NULL)
	{
		line_number++;
		opd = strtok(line, "\t\n\r");

		if (opd != NULL && opd[0] != '#')
		{
			my_instruction(opd, &stack, line_number);
		}
	}
	if (line != NULL)
	{
		free(line);
	}
	while (stack != NULL)
	{
		stack = stack->next;
		free(temp);
	}
	return (EXIT_SUCCESS);
}
