#ifndef _PRINTF_H
#define _PRINTF_H
int _printf(const char *format, ...);
/**
 * sruct fmt - to link given char to function to print
 * @in: char evaluated
 * @fn: function pointer to use
 */
typedef struct fmt
{
	char in;
	void (*fn)(va_list al);
} fmt;
#endif
