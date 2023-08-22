#include "main.h"
/**
* handle_print - Print arg
* @fmt: Formatted to print the arg
* @list: List of arg to be printed
* @ind: ind
* @buffer: Buffer array to handle print
* @flags: Cal active flags
* @width: width
* @precision: Precision
* @size: Size specified
* Return: 1 or 2;
*/
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
	int d, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
	{'c', print_char}, {'s', print_string}, {'%', print_percent},
	{'i', print_int}, {'d', print_int}, {'b', print_binary},
	{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
	{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
	{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (d = 0; fmt_types[d].fmt != '\0'; d++)
	if (fmt[*ind] == fmt_types[d].fmt)
	return (fmt_types[d].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[d].fmt == '\0')
	{
	if (fmt[*ind] == '\0')
	return (-1);
	unknow_len += write(1, "%%", 1);
	if (fmt[*ind - 1] == ' ')
	unknow_len += write(1, " ", 1);
	else if (width)
	{
	--(*ind);
	while (fmt[*ind] != ' ' && fmt[*ind] != '%')
	--(*ind);
	if (fmt[*ind] == ' ')
	--(*ind);
	return (1);
	}
	unknow_len += write(1, &fmt[*ind], 1);
	return (unknow_len);
	}
	return (print_char);
