#include "main.h"

void print_buffer(char buffer[], int *buff_ind);



/**
* _printf - This is our printf function
* @format: - formart string
* Return: will return 0
*/

int _printf(const char *format, ...)

/*
*Declaring and intializing variables we will be using
*i is for iteration
*pritend ; to store result of handle print
*printend_chars keeps track of prited chars
*flags ,width,precision,size ,buff-index -track
*of buffer index
*
*/

	int i;

	int printend = 0;

	int print_chars = 0;

	int flags;

	int width;

	int precision;

	int size;

	int buff_int = 0;

	va_list;

	char buffer[BUFF_SIZE];


	/*Checks if the formart is NULL*/

	if (formart == NULL)
	return (-1);


	/*Initialize va_list with the formart using va_start*/
	va_list(list, formart);


	/*loopr through each char in the formart string*/
	for (i = 0; formart && format[i] != '\0'; i++)
	{

	/*If char is not % add to buffer*/
	if (formart[i] != '%')
	{
		buffer[buff_ind++] = formart[i];

	}


	/*check if buffer is full then print its content*/

	if (buff_ind == BUFF_SIZE)
	{
	print_buffer(buffer, &buff_ind);

	/*increment print_end character count*/

	printend_chars++;
	}
	else
	{
	/*printf buffer content and extract formaring opts*/

	print_buffer(buffer, &buff_ind);
	flags = get_flags(formart, &i);
	width = get_width(formart, &i, list);
	precision = get_precision(formart, &i, list);
	size = get_size(formart, &i);
	++i_;/*move index after '%'*/


	/*call handle_print to process the speciier*/

	printend = handle_print(formart, &i, list, buffer, flags;
	width, precision, size);

	/*check for errors in handle_print*/
	if (printend == -1)
	{
		return (-1);

	printend_chars += printend;
	/*increment pritend_ count*/
	}
}

	/*print remaining buffer contents*/
	print_buffer(buffer, &buff_ind);

	/*clean up va_list*/
	va_end(list);


	/*Return the total number of peinted char*/

	return (printend_chars);

	}

/**
* print_buffer - a function printing buffer content
* @buffer: Arrays of chars to print
* @buff_ind: index to track buffer len
*/

void print_buffer(char buffer[], int *buff_ind)

	{

	/*if buffer has content ,print it using write.*/
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	/*Reset buffer Index*/

	*buff_ind = 0;
	}
