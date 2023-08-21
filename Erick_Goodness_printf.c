
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);



/**
 * _printf -This is our printf function
 * @format:This is our format string
 * Return: Printed chracter
 */



int _printf(const char *format, ...)
{

	int printed = 0, printed_chars = 0;


	int flags, width;

	int e;

	int precision, size, buff_ind = 0;

	va_list list;
	char buffer[BUFF_SIZE];




	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (e = 0; format && format[e] != '\0'; e++)
	{
		if (format[e] != '%')
		{
			buffer[buff_ind++] = format[e];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}



		else







		{
			print_buffer(buffer, &buff_ind);

			flags = get_flags(format, &e);

			width = get_width(format, &e, list);

			precision = get_precision(format, &e, list);

			size = get_size(format, &e);

			++e;

			printed = handle_print(format, &e, list, buffer,

				flags, width, precision, size);

			if (printed == -1)

				return (-1);

			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}


/**
 * print_buffer - This will print content of a buffer
 * @buffer: Our atrrays
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
