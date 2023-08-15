#include "monty.h"

/**
 * main - Entry point of the program.
 * @argc: The number of command line arguments.
 * @argv: The command line arguments.
 *
 * Description: This function reads a file containing Monty byte codes and
 * executes them. If the file contains an invalid instruction, it prints an
 * error message and exits.
 *
 * Return: 0 on success, EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL, *filename = NULL, **lines = NULL, **opcodes = NULL;
	char *command[] = {"push", "pall", "pint", "pop", "nop"};
	stack_t *head = NULL;
	unsigned int lineN = 0, opcodeIndex = 0;
	int status = -1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	buffer = read_file(filename);
	lines = tokenizer(buffer, "\n");
	for (lineN = 0; lines[lineN]; lineN++)
	{
		opcodes = tokenizer(lines[lineN], " ");
		for (opcodeIndex = 0; command[opcodeIndex]; opcodeIndex++)
		{
			if (strcmp(opcodes[0], command[opcodeIndex]) == 0)
			{
				functions(opcodes[0], &head, (lineN + 1));
				status = 1;
				break;
			}
			else
				status = -1;
		}
		if (status != 1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", (lineN + 1), opcodes[0]);
			exit(EXIT_FAILURE);
		}
	}
	free(opcodes);
	free(lines);
	free(buffer);
	return (0);
}
