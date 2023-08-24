#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, goodness = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buffer(buffer, goodness), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = get_at_alx(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					we_learnt_to_handle_buff(buffer, format[i], goodness), len++, i--;
				}
				else
				{
					len += function(arguments, buffer, goodness);
					i += at_alx(format, i + 1);
				}
			} i++;
		}
		else
			we_learnt_to_handle_buff(buffer, format[i], goodness), len++;
		for (goodness = len; goodness > 1024; goodness -= 1024)
			;
	}
	print_buffer(buffer, goodness), free(buffer), va_end(arguments);
	return (len);
}
