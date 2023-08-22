#include "main.h"

/**
 * print_char - Prints a character
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates actives
 * @width: Widths
 * @precision: Precisin
 * @size: Size specifier
 * Return: Number of characters
 */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************* PRINT A STRING ***************/

/**
 * print_string - Prints a strings
 * @types: List a
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size 
 * Return: Number of chars
 */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, e;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (e = width - length; e > 0; e--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (e = width - length; e > 0; e--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/***************NT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign-
 * @types: Lista of argus
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision:specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buf  to handle print
 * @flags:  Calculates active flags
 * @width: get wid
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int e = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[e--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[e--] = (num % 10) + '0';
		num /= 10;
	}

	e++;

	return (write_number(is_negative, e, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates
 * @width: get width.
 * @precision: Precision specification
 * @size: Size sper
 * Return: Numbers ....
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, e, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (e = 1; e < 32; e++)
	{
		m /= 2;
		a[e] = (n / m) % 2;
	}
	for (e = 0, sum = 0, count = 0; e < 32; e++)
	{
		sum += a[e];
		if (sum || e == 31)
		{
			char z = '0' + a[e];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
