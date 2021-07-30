#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


/**
 * fnStr - print Str
 * @al: argument list
 * @buf: buffer with string to print
 * Return: size of argument
 */
int fnStr(va_list al, char **buf)
{
	int count = 0;
	char *str;

	str = (va_arg(al, char*));
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		**buf = *str;
		(*buf)++;
		str++;
		count++;
	}
	return (count);
}