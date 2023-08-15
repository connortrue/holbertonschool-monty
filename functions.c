#include "monty.h"
/**
 * tokenizer - Splits a string into tokens
 * @str: The string to tokenize
 * @sep: The separator used to tokenize the string
 *
 * Return: Pointer to an array of tokens
 */
char **tokenizer(char *str, char *sep)
{
	char **tokens = NULL;
	char *token = strtok(str, sep);
	int count = 0;

	while (token != NULL)
	{
		tokens = realloc(tokens, (count + 1) * sizeof(char *));
		if (tokens == NULL)
		{
			fprintf(stderr, "Error: realloc failed\n");
			exit(EXIT_FAILURE);
		}

		tokens[count] = strdup(token);
		if (tokens[count] == NULL)
		{
			fprintf(stderr, "Error: strdup failed\n");
			exit(EXIT_FAILURE);
		}

		count++;
		token = strtok(NULL, sep);
	}

	tokens = realloc(tokens, (count + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		fprintf(stderr, "Error: realloc failed\n");
		exit(EXIT_FAILURE);
	}
	tokens[count] = NULL;

	return (tokens);
}
/**
 * functions - Execute the correct function based on the opcode
 * @array: The array storing the opcode and its arguments
 * @head: Double pointer to the head of the stack
 * @line: The line number currently being executed
 *
 * Description: It is assumed that the opcodes are correctly implemented.
 * If an unknown opcode is encountered, the program will print an error message
 * and exit with status EXIT_FAILURE.
 */
void functions(char *array, stack_t **head, unsigned int line)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		/* Add more opcodes here */
		{NULL, NULL}
	};
	while (opcodes[i].opcode)
	{
		if (strcmp(array, opcodes[i].opcode) == 0)
			opcodes[i].f(head, line);
		i++;
	}

	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, array);
		exit(EXIT_FAILURE);
	}
}
/**
 * read_file - Reads a file and stores its content in a buffer
 * @filename: The name of the file to read
 *
 * Return: Pointer to a buffer containing the content of the file
 * If the file cannot be opened or read, or if the buffer cannot be allocated,
 * the function will print an error message and exit with status EXIT_FAILURE.
 */
char *read_file(char *filename)
{
	int fd = 0, line = 0;
	char *buffer = NULL;

	if (filename == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	fd = open(filename, O_RDONLY);
	if (fd == 00)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	buffer = malloc(BUFSIZ);
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(buffer);
		exit(EXIT_FAILURE);
	}

	line = read(fd, buffer, BUFSIZ);
	if (line == 00)
		return (0);

	close(fd);
	return (buffer);
}
