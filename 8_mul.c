#include "monty.h"
/**
 * _mul - multiplies the top two elements in the stack
 * @stack: stack
 * @line_number: line_number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int mul;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		free_list(stack);
		free(stack);
		exit(EXIT_FAILURE);
	}

	mul = ((*stack)->next)->n * (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = mul;
}
