#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * fnChar - print char
 * @al: argument list
 */
int fnChar(va_list al, __attribute__((unused)) char **buff)
{
	putchar(va_arg(al, int));
	return (0);
}
/**
 * fnInt - print Int
 * @al: argument list
 */
int fnInt(va_list al, __attribute__((unused)) char **buf)
{
	printf("%d", va_arg(al, int));
	return (0);
}
/**
 * fnStr - print Str
 * @al: argument list
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
		{'c', fnChar},
		{'i', fnInt},
		{'d', fnInt},
		{'f', fnFloat},
		{'s', fnStr}
	};
	int ifmt, iformat = 0, count = 0;
	va_list al;
	char buf[2000];
	char *pbuf;

	pbuf = buf;
	va_start(al, format);
	
	while (format && format[iformat] != '\0')
	{
		if (format[iformat] == '%')
		{
			iformat++;
			ifmt = 0;
			if (format[iformat] == '%')
				printf("%%");
			else
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
		}
		else
		{
			*pbuf = format[iformat];
			pbuf++;
		}
		iformat++;
	}
	_putchar(buf, pbuf - (char*)buf);
	va_end(al);
	return (count);
}
