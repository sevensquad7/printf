#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * fnChar - print char
 * @al: argument list
 * @buf: buffer with string to print
 * Return: size of argument
 */
int fnChar(va_list al, char **buf)
{
	int count = 0;

	**buf = va_arg(al, int);
	(*buf)++;
	count++;
	return (count);
}