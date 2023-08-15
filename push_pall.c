#include "monty.h"
void push(stack_t **stack, unsigned int line_number)
{
    int value = line_number;
    (void)line;

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

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

