#include "monty.h"
/**
 * _push - pushes an element to the stack
 * @stack: pointer
 * @line_number: line number
 * @token: value converted to int
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number, char *token)
{
	stack_t *newone = NULL;
	unsigned int x;

	if (!token)
	{
		printf("L%d: usage: push integer\n", line_number);
		val = 1;
		exit(EXIT_FAILURE);
	}

	for (x = 0; token[x] != '\0'; x++)
	{
		if (token[x] == '-') /* account for negative */
			x++;
		if (isdigit(token[x]) == 0)
		{
			printf("L%d: usage: push integer\n", line_number);
			val = 1;
			exit(EXIT_FAILURE);
		}
	}

	newone = malloc(sizeof(stack_t));
	if (!newone)
	{
		printf("Error: malloc failed\n");
		val = 1;
		exit(EXIT_FAILURE);
	}

	newone->n = atoi(token);
	newone->prev = NULL;
	newone->next = NULL;
	if (*stack)
	{
		newone->next = *stack;
		(*stack)->prev = newone;
	}
	*stack = newone;
}

/**
 * _pall - prints all the values on the stack, starting from the top
 * @stack: pointer to stack
 * @line_number: line number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *racer = *stack;

	UNUSED(line_number);

	while (racer)
	{
		printf("%d\n", racer->n);
		racer = racer->next;
	}
}
