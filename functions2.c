#include "main.h"
/**
 * for_string - prints a string from va_list
 * @string: passed string from func
 * Return: buffer string
*/
char *for_string(const char *string)
{
	char *buffer_store;
	int index = 0;

	if (string == NULL)
		return (NULL);
	buffer_store = (char *)malloc(strlen(string) + 1);
	if (buffer_store == NULL)
		exit(EXIT_FAILURE);
	while (*string != '\0')
	{
		*(buffer_store + index) = *string;
		index++;
		string++;
	}
	*(buffer_store + index) = '\0';
	return (buffer_store);
}
/**
 * for_reverse - prints a string from va_list
 * @string: passed string from func
 * Return: buffer string
*/
char *for_reverse(const char *string)
{
	char *buffer_store;
	int index = 0;
	int end = strlen(string) - 1;

	if (string == NULL)
		return (NULL);
	buffer_store = (char *)malloc(strlen(string) + 1);
	if (buffer_store == NULL)
		exit(EXIT_FAILURE);
	while (end >= 0)
	{
		*(buffer_store + index) = *(string + end);
		index++;
		end--;
	}
	*(buffer_store + index) = '\0';
	return (buffer_store);
}
/**
 * for_unsigned - this function prints takes an int and put it in a string
 * @number: the number to convert to string
 * Return: the string holding the number
 */
char *for_unsigned(int number)
{
	char *buffer, *tmp;
	int counter = 0;
	int start = 0;
	int end;

	buffer = (char *)malloc(2 * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (number < 0)
	{
		number *= -1;
	}
	do {
		buffer[counter++] = '0' + (number % 10);
		number /= 10;
		tmp = (char *)realloc(buffer, (counter) * sizeof(char));

		if (tmp == NULL)
		{
			free(buffer);
			return (NULL);
		}
		buffer = tmp;
	} while (number != 0);
	buffer[counter] = '\0';
	end = counter - 1;
	while (start < end)
	{
		char temp = buffer[start];

		buffer[start++] = buffer[end];
		buffer[end--] = temp;
	}
	return (buffer);
}
