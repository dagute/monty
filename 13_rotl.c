#include "monty.h"
/**
 * _rotl - rotates the stack to the top
 * @stack: stack
 * @line_number: line number
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *end = *stack;

	UNUSED(line_number);

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (end->next)
		end = end->next;

	end->next = *stack;
	(*stack)->prev = end;
	*stack = (*stack)->next;
	end->next->next = NULL;
	(*stack)->prev = NULL;
}
