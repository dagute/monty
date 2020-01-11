#include "monty.h"
/**
 * _pchar - prints the char at the top of the stack, followd by a new line
 * @stack: stack
 * @line_number: line_number
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;

	while (num < 0 || num > 127)
	{
		printf("L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(num);
	putchar('\n');

}
