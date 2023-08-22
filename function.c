#include "main.h"

/**
* print_char - Print character
* @types: List arg
* @buffer: Buffer array
* @flags:  Cal active flags
* @width: Width
* @precision: Precision specific
* @size: Size specified
* Return: Num of character to be printed
*/
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char d = va_arg(types, int);

	return (handle_write_char(d, buffer, flags, width, precision, size));
}

/**
* print_string - Print a str
* @types: List arg
* @buffer: Buffer array
* @flags:  Cal active flags
* @width: Width
* @precision: Precision specific
* @size: Size specified
* Return: Num of character to be printed
*/
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int length = 0, f;
	char *mar = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (mar == NULL)
	{
	mar = "(null)";
	if (precision >= 6)
	mar = "      ";
	}

	while (mar[length] != '\0')
	length++;

	if (precision >= 0 && precision < length)
	length = precision;

	if (width > length)
	{
	if (flags & F_MINUS)
	{
	write(1, &mar[0], length);
	for (f = width - length; f > 0; f--)
	write(1, " ", 1);
	return (width);
	}
	else
	{
	for (f = width - length; f > 0; f--)
	write(1, " ", 1);
	write(1, &mar[0], length);
	return (width);
	}
	}

	return (write(1, mar, length));
}
/**
* print_percent - Print percentage sign
* @types: List arg
* @buffer: Buffer array
* @flags:  Cal active flags
* @width: Width
* @precision: Precision specific
* @size: Size specified
* Return: Num of character to be printed
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

/**
* print_int - Print an integar
* @types: List arg
* @buffer: Buffer array
* @flags:  Cal active flags
* @width: Width
* @precision: Precision specific
* @size: Size specified
* Return: Num of character to be printed
*/
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int p = BUFF_SIZE - 2;
	int is_negative = 0;
	long int y = va_arg(types, long int);
	unsigned long int sum;

	y = convert_size_number(y, size);

	if (y == 0)
		buffer[p--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	sum = (unsigned long int)y;

	if (y < 0)
	{
	sum = (unsigned long int)((-1) * y);
	is_negative = 1;
	}

	while (sum > 0)
	{
	buffer[p--] = (sum % 10) + '0';
	sum /= 10;
	}

	p++;

	return (write_number(is_negative, p, buffer, flags, width, precision, size));
}

/**
* print_binary - Print unsigned num
* @types: List arg
* @buffer: Buffer array
* @flags:  Cal active flags
* @width: Width
* @precision: Precision specific
* @size: Size specified
* Return: Num of character to be printed
*/
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	unsigned int e, p, w, num;
	unsigned int g[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	e = va_arg(types, unsigned int);
	p = 2147483648; /* (2 ^ 31) */
	g[0] = e / p;
	for (w = 1; w < 32; w++)
	{
	p /= 2;
	g[w] = (e / p) % 2;
	}
	for (w = 0, num = 0, count = 0; w < 32; w++)
	{
	num += g[w];
	if (num || w == 31)
	{
	char z = '0' + g[w];

	write(1, &z, 1);
	count++;
	}
	}
	return (count);
}

