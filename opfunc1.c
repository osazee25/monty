#include "monty.h"
/**
 * digit - checks if a string contains only digits
 * @s: string
 * Return: 1 if digit otherwise 0
*/
int digit(char *s)
{	
	int i;
	int flag = 0;

	if (s == NULL)
	{
		return (0);
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		if (!isdigit(s[i]))
	{
		break;
	}

	flag = 1;
	}

	if (flag)
	{
	load.data = atoi(s);
	return (1);
	}

    return (0);
}
