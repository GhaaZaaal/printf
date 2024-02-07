#include "main.h"
/**
 * specifiers_int - function to check for the char if specifier return func
 *@is_it_specifier: the string contains the specifier character to check
 * Return: a pointer to the function that will be called
 */
char *(*specifiers_int(char is_it_specifier))(int)
{
	int index = 0;

	arg_executed arr_type_and_function[] = {
		{'d', for_int},
		{'i', for_int},
		{'u', for_unsigned},
		{'%', for_module},
		{'c', for_char},
		{'b', for_binary},
		{'o', for_octal},
		{'x', for_hex},
		{'X', for_HEX},
		{'\0', NULL},
	};
	while (arr_type_and_function[index].type)
	{
		if (is_it_specifier == arr_type_and_function[index].type)
		{
			return (arr_type_and_function[index].function_for_type);
		}
		index++;
	}
	return (NULL);
}
/**
 * for_char - to print a character
 *@character: the character to print
 * Return: The character to print
 */
char *for_char(int character)
{
	char *buffer_store;

	buffer_store = (char *)malloc(sizeof(char) * 2);
	buffer_store[0] = character;
	buffer_store[1] = '\0';
	return (buffer_store);
}

/**
 * for_int - this function prints takes an int and put it in a string
 * @number: the number to convert to string
 * Return: the string holding the number
 */
char *for_int(int number)
{
	char *buffer, *tmp;
	int counter = 0, start = 0, end, sign = 0;

	buffer = (char *)malloc(2 * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (number < 0)
		number *= -1, sign = 1;
	do {
		buffer[counter++] = ('0' + (number % 10));
		number /= 10;
		tmp = (char *)realloc(buffer, (counter) * sizeof(char));

		if (tmp == NULL)
		{
			free(buffer);
			return (NULL);
		}
		buffer = tmp;
	} while (number != 0);
	if (sign == 1)
	{
		buffer[counter] = '-', counter++;
		tmp = (char *)realloc(buffer, (counter) * sizeof(char));
	}
	buffer[counter] = '\0', end = counter - 1;
	while (start < end)
	{
		char temp = buffer[start];

		buffer[start++] = buffer[end];
		buffer[end--] = temp;
	}
	return (buffer);
}
/**
 * for_module - prints module
 * @a: the '%' char
 * Return: made string
 */
char *for_module(int a)
{
	char *buffer_store = (char *)malloc(2 * sizeof(char));

	buffer_store[0] = a;
	buffer_store[1] = '\0';
	return (buffer_store);
}
/**
 * specifiers_str - checks for string specifires
 * @is_it_specifier: passed char to check here
 * Return: made string
 */
char *(*specifiers_str(char is_it_specifier))(const char *)
{
	specifier_str array[] = {
		{'R', for_rot13},
		{'s', for_string},
		{'r', for_reverse},
		{'\0', NULL},
	};
	int index = 0;

	while (array[index].type)
	{
		if (is_it_specifier == array[index].type)
		{
			return (array[index].function_for_type);
		}
		index++;
	}
	return (NULL);
}
