#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

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
	if (format == NULL)
		count = -1;
	return (count);
}
