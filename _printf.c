#include "main.h"
#include <stdarg.h>

/**
 * _printf - Prints various code functions
 * @format - Pointer to conversion specifiers
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	/* Creating a list that will hold the arguments */
	va_list args;
	/* Creating an argument counter as well as the type checker */
	int arg_count, checker, sizeStr = 0;
	char *str;

	/* STarting the function */
	va_start(args, format);

	while (format[checker] != '\0')
	{
		switch (format[checker])
		{
			case 'c':
				arg_count = arg_count + 1;
				printf("%c", va_arg(args, int));
				break;
			case 's':
				str = va_arg(args, char *);
				printf("%s", str);
				sizeStr = sizeof(*str)/sizeof(char);
				arg_count += sizeStr;
				break;
			case '%':
				continue;
			default:
				continue;
		}
		checker++;
	}

	return (arg_count);
}
