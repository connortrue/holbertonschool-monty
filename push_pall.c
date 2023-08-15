void push(stack_t **stack, unsigned int line_number)
{
    // Get the value to push from the `opcodes` array
    int value = atoi(opcodes[line_number]);

    // Create a new stack node
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    // Set the value and pointers of the new node
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    // Update the previous node's pointer
    if (*stack != NULL)
        (*stack)->prev = new_node;

    // Update the stack head
    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

