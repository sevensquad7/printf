#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


/**
 * fnInt - print Int
 * @al: argument list
 * @buf: buffer with string to print
 * Return: size of argument
 */
int fnInt(va_list al, char **buf)
{
	int count = 0;
	char number_str[10];
	int number = va_arg(al, int);

	sprintf(number_str, "%d", number);
	while (number_str[count])
	{
		**buf = number_str[count];
		(*buf)++;
		count++;
	}
	return (count);
}