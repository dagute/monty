#include "monty.h"
/**
 * _mod - computes the rest of the division of the second top element of the
 * stack by the top element of the stack
 * @stack: stack
 * @line_number: line number
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	int mod;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		free_list(stack);
		free(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		free_list(stack);
		free(stack);
		exit(EXIT_FAILURE);
	}

	mod = ((*stack)->next)->n % (*stack)->n;

	(*stack)->next->n = mod;
	_pop(stack, line_number);
}
