#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"
/**
 * fnChar - print char
 * @al: argument list
 */
void fnChar(va_list al)
{
	printf("%c", va_arg(al, int));
}
/**
 * fnInt - print Int
 * @al: argument list
 */
void fnInt(va_list al)
{
	printf("%d", va_arg(al, int));
}
/**
 * fnStr - print Str
 * @al: argument list
 */
void fnStr(va_list al)
{
	char *mychar;

	mychar = va_arg(al, char*);
	if (mychar == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", mychar);
}
/**
 * fnFloat - print Float
 * @al: argumento list
 */
void fnFloat(va_list al)
{
	printf("%f", va_arg(al, double));
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
				printf("%%");
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
			printf("%c", format[iformat]);
		lenformat++;
		iformat++;
	}
	va_end(al);
	return (lenformat);
}
