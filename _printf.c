#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "holberton.h"
/**
 * fnChar - print char
 * @al: argument list
 */
void fnChar(va_list al)
{
	putchar(va_arg(al, int));
}
/**
 * fnStr - print Str
 * @al: argument list
 */
void fnStr(va_list al)
{
	int i, len = 0;
	char *mychar = va_arg(al, char*);

	while(*(mychar + len) != '\0')
		len++;
	for (i = 0; i < len - 1; i++)
		putchar(*(mychar + i));
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
		{'s', fnStr}
	};
	int ifmt, iformat = 0, lenformat = 0;
	va_list al;

	va_start(al, format);
	while (format && format[iformat] != '\0')
	{
		if (format[iformat] == '%')
		{
			iformat++;
			ifmt = 0;
			if (format[iformat] == '%')
			{
				putchar('%');
				putchar('%');
			}
				else
			{
				while (fmts[ifmt].in != '\0')
				{
					if (fmts[ifmt].in == format[iformat])
					{
						fmts[ifmt].fn(al);
						break;
					}
					ifmt++;
				}
			}
		}
		else
			putchar(format[iformat]);
		lenformat++;
		iformat++;
	}
	va_end(al);
	return (lenformat);
}
