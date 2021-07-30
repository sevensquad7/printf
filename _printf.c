#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "holberton.h"

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

/**
 * _printf - print everything
 * @format: string with chars to evaluate
 * Return: length of format string
 */
int _printf(const char *format, ...)
{
	fmt fmts[] = {
		{'c', fnChar}, { 'i', fnInt}, {'d', fnInt}, {'f', fnFloat}, {'s', fnStr}};
	int ifmt, iformat = 0, count = 0;
	va_list al;
	char buf[2000], *pbuf = buf;

	va_start(al, format);
	while (format && format[iformat] != '\0')
	{
		if (format[iformat] == '%')
		{
			iformat++;
			ifmt = 0;
			if (format[iformat] != '%')
			{
				while (fmts[ifmt].in != '\0')
				{
					if (fmts[ifmt].in == format[iformat])
					{
						count += fmts[ifmt].fn(al, &pbuf);
						break;
					}
					ifmt++;
				}
			}
			else
			{
				*pbuf = format[iformat];
				pbuf++;
				count++;
			}
		}
		else
		{
			*pbuf = format[iformat];
			pbuf++;
			count++;
		}
		iformat++;
	}
	_putchar(buf, pbuf - (char *)buf);
	va_end(al);
	return (count);
}
