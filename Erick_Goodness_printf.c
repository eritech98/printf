#include "main.h"

void print_buffer(char buffer[], int *buff_ind);



/**
* Erick_Goodness_printf - This is our printf function
* @format: - formart string
* Return: will return 0
*/

int Erick_Goodness_printf(const char *format, ...)

/*
*Declaring and intializing variables we will be using
*i is for iteration
*pritend ; to store result of handle print
*printend_chars keeps track of prited chars
*flags ,width,precision,size ,buff-index -track
*of buffer index
*
*/

	int i_;

	int printend_ = 0;

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
	for (i_ = 0; formart && format[i_] != '\0'; i_++)
	{

	/*If char is not % add to buffer*/
	if (formart[i_] != '%')
	{
		buffer[buff_ind++] = formart[i_];

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
	flags = get_flags(formart, &i_);
	width = get_width(formart, &i_, list);
	precision = get_precision(formart, &i_, list);
	size = get_size(formart, &i_);
	++i_;/*move index after '%'*/


	/*call handle_print to process the speciier*/

	printend_ = handle_print(formart, &i_, list, buffer, flags;
	width, precision, size);

	/*check for errors in handle_print*/
	if (printend_ == -1)
	{
		return (-1);

	printend_chars += printend_;
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
