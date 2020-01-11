#include "monty.h"
/**
 * _div - divides the second top element of the stack by the top element
 * @stack: stack
 * @line_number: line number
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int div;

	if (!*stack || !(*stack)->next)
	{
		printf("L%u: can't div, stack too short\n", line_number);
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

	div = (*stack)->next->n / (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = div;
}
