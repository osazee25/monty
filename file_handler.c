#define _POSIX_C_SOURCE 200809L
#include "monty.h"

load_t load = {NULL, NULL, NULL, 0, 0};

void file_handle(char **av)
{
	char *buf = NULL, *file = av[1], **avcode;
	FILE *line = fopen(file, "r");
	size_t size;
	int line_no = 0;
	ssize_t nread;
	stack_t *stack = NULL;
	void (*func)(stack_t **, unsigned int);

	load.file = line;
	if (line == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	for (line_no = 1; (nread = getline(&buf, &size, line)) >= 0; line_no++, load.count = line_no)
	{
		load.buf = buf;
		avcode = stringsplit(buf);
		if (avcode == NULL)
	{
		continue;
	}
	func = getfunc(avcode, &stack);
	if (avcode[0] != NULL && func == NULL)
	{
		load.code = avcode[0];
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, load.code);
		exit(EXIT_FAILURE);
	}
	free_av(avcode);
	if (func != NULL)
		func(&stack, line_no);
	}

	free(buf);
	fclose(line);
	free_stack(stack);
}
