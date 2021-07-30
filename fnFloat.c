#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * fnFloat - print Float
 * @al: argumento list
 * @buf: buffer with string to print
 * Return: size of argument
 */
int fnFloat(va_list al, __attribute__((unused)) char **buf)
{
	printf("%f", va_arg(al, double));
	return (0);
}