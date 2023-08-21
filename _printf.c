#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - this is our Printf function
 * @format:This is the formart string
 * Return: Printed chars.
 */


/*this is the valiadric function*/

int _printf(const char *format, ...)
{
	int e, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];


/*checks IF forMart is NULL*/
	if (format == NULL)
		return (-1);

	va_start(list, format);





/* va_list with the formart*/

	for (e = 0; format && format[e] != '\0'; e++)
	{
		if (format[e] != '%')
		{
			buffer[buff_ind++] = format[e];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
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
 * print_buffer - This will print  the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind:This index represents length
 */


void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)






		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
