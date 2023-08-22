#include "main.h"

/**
* print_unsigned - Print unsigned num
* print_char - Print character
* @types: List arg
* @buffer: Buffer array
* @flags:  Cal active flags
* @width: Width
* @precision: Precision specific
* @size: Size specified
* Return: Num of character to be printed
*/
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[z--] = (num % 10) + '0';
	num /= 10;
	}

	z++;

	return (write_unsgnd(0, z, buffer, flags, width, precision, size));
}

/**
* print_octal - Print unsigned num in octal notation
* print_char - Print character
* @types: List arg
* @buffer: Buffer array
* @flags:  Cal active flags
* @width: Width
* @precision: Precision specific
* @size: Size specified
* Return: Num of character to be printed
*/
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int l = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[l--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[l--] = (num % 8) + '0';
	num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
	buffer[l--] = '0';

	l++;

	return (write_unsgnd(0, l, buffer, flags, width, precision, size));
}

/**
* print_hexadecimal - Print an unsigned num hexadecimal notation
* print_char - Print char
* @types: List arg
* @buffer: Buffer array
* @flags:  Cal active flags
* @width: Width
* @precision: Precision specific
* @size: Size specified
* Return: Num of character to be printed
*/
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
	flags, 'x', width, precision, size));
}


/**
* print_hexa_upper - Print unsigned num in upper hexadecimal notation
* print_char - Print character
* @types: List arg
* @buffer: Buffer array
* @flags:  Cal active flags
* @width: Width
* @precision: Precision specific
* @size: Size specified
* Return: Num of character to be printed
*/
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
	flags, 'X', width, precision, size));
}

/**
* print_hexa - Prints a hexadecimal number in lower or upper
* @types: Lista of arg
* @map_to: Array of values
* @buffer: Buffer array to print
* @flags:  Cal active flags
* @flag_ch: Cal active flags
* @width: width
* @precision: specification
* @size: specifier
* @size: specification
* Return: Num of characters printed
*/
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[a--] = map_to[num % 16];
	num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
	buffer[a--] = flag_ch;
	buffer[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
