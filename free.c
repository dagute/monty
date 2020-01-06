#include "monty.h"
/**
 * free_list - frees the linked list
 * @stack: the stack to free
 */
void free_list(stack_t **stack)
{
	stack_t *tmp;

	if (*stack == NULL)
		return;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
/**
 * free_all - frees linked list
 * @stack: linked list to free
 * @l: line from getline to be free
 * @arc: file to pointer
 * Return: N/A, void function
 */

void free_all(stack_t *stack, char *l, FILE *arc)
{
	if (stack != NULL)
		free_list(&stack);
	free(l);
	fclose(arc);
}
