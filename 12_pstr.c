#include "monty.h"
/**
 * _pstr - prints the string starting at the top of the stack, followed
 * by a new line
 * @stack: stack
 * @line_number: line number
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *racer = *stack;

	(void)line_number;

	if (stack == NULL || *stack == NULL || val == 0)
	{
		printf("\n");
		return;
	}
	while (racer != NULL)
	{
		if (isascii(racer->n) && racer->n != 0)
			printf("%c", racer->n);
		else
		{
			printf("\n");
			return;
		}
		racer = racer->next;
	}
	printf("\n");
}
