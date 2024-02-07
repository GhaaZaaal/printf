#include "main.h"
/**
 * for_binary - function prints the binary number of a number
 * @number: the number to be printed
 * Return: the string holding the binary number
 */
char *for_binary(int number)
{
	char *buffer, *tmp;
	int counter = 0;
	int start = 0;
	int end;

	buffer = (char *)malloc(1 * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	do {
		buffer[counter++] = '0' + (number % 2);
		number /= 2;
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
/**
 * for_rot13 - function convert the first half of the alphabet to the next
 * @string: the string to be checked and convert
 * Return: the string holding the new converted string
 */
char *for_rot13(const char *string)
{
	int i, indexer = 0;
	char rot13[] = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklm NOPQRSTUVWXYZABCDEFGHIJKLM";
	char *pointer_string = (char *)malloc(sizeof(string) * sizeof(char));

	while (*string)
	{
		pointer_string[indexer] = *string;
		indexer++;
		string++;
	}
	while (indexer >= 0)
	{
		for (i = 0; i <= 53; i++)
		{
			if (pointer_string[indexer] == rot13[i])
			{
				pointer_string[indexer] = ROT13[i];
				indexer--;
				break;
			}
		}
	}
	return (pointer_string);
}
/**
 * for_octal - function converts an integer to octal
 * @numberr: the number to convert
 * Return: the string holding the octal representation
 */
char *for_octal(int numberr)
{
	unsigned int number = numberr;
	char *buffer, *tmp;
	int counter = 0;
	int start = 0;
	int end;

	buffer = (char *)malloc(1 * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	do {
		buffer[counter++] = '0' + (number % 8);
		number /= 8;
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
/**
 * for_hex - function converts an integer to hexadecimal small-endian
 * @numberr: the number to convert
 * Return: the string holding the octal representation
 */
char *for_hex(int numberr)
{
	unsigned int number = numberr;
	char *buffer, *tmp;
	int counter = 0, start = 0, end;

	buffer = (char *)malloc(3 * sizeof(char));
	if (buffer == NULL)
		return (NULL);

	do {
		if (number % 16 > 9)
		{
			buffer[counter++] = 'a' + (number % 16) - 10;
		}
		else
		{
			buffer[counter++] = '0' + (number % 16);
		}
		number /= 16;
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
/**
 * for_HEX - function converts an integer to hexadecimal small-endian
 * @numberr: the number to convert
 * Return: the string holding the octal representation
 */
char *for_HEX(int numberr)
{
	unsigned int number = numberr;
	char *buffer, *tmp;
	int counter = 0, start = 0, end;

	buffer = (char *)malloc(3 * sizeof(char));
	if (buffer == NULL)
		return (NULL);

	do {
		if (number % 16 > 9)
		{
			buffer[counter++] = 'a' + (number % 16) - 10;
		}
		else
		{
			buffer[counter++] = '0' + (number % 16);
		}
		number /= 16;
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
