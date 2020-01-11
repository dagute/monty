#include "monty.h"
/**
 * _rotr - otates the stack to the bottom
 * @stack: stack
 * @line_number: line_number
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	UNUSED(line_number);
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (top->next)
		top = top->next;

	top->prev->next = NULL;
	top->next = *stack;
	top->prev = NULL;
	(*stack)->prev = top;
	*stack = top;
}
