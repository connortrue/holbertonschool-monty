#include "monty.h"
/**
 * push - Adds a new node to the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: The value to be added to the stack
 *
 * Description: This function creates a new node, sets its valu to line_number,
 * and adds it to the top of the stack. If the stack is not emty, the new node
 * becomes the new top of the stack and the old top node beces the second node
 * in the stack. If the stack is empty, the new node becomes the only node in
 * the stack. If memory allocation fails, the function prints an error message
 * and exits with status EXIT_FAILURE.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value = line_number;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
/**
 * pall - Printsall the values on the stack, starting from the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: The line number currently being executed (unused)
 *
 * Description: This function iterates through the stack from top to bottom,
 * printing the value of each node. The line_number parameter is not used in
 * this function, but is included to conform to the format used by other funct
 * that interact with the stack and need to know the current line number.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

