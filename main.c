#include "monty.h"
/**
 * main - receives arguments and then passes to stack
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if success
 */
int  val = 0;
int main(int argc, char **argv)
{
	char *l, *symbol;
	unsigned int line_num;
	size_t len;
	stack_t *stack;
	FILE *ar;

	while (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ar = fopen(argv[1], "r");
	if (!ar)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stack = NULL;
	l = symbol = NULL;
	len = 0;
	for (line_num = 0; getline(&l, &len, ar) != -1 && val == 0; ++line_num)
	{
		symbol = strtok(l, "\n\t\r ");
		if (!symbol || strncmp(symbol, "#", 1) == 0)
			continue;
		if (strcmp(symbol, "push") == 0)
		{
			symbol = strtok(NULL, "\n\t\r ");
			_push(&stack, line_num, symbol);
		}
		else
			op_func(symbol, &stack, line_num);
	}
	free_all(stack, l, ar);
	if (val != 0)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
