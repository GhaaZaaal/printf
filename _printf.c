#include "main.h"
/**
 * _printf - function to use like printf function
 * @format: format string to be countered
 * Return: the number of bytes written
 */
int _printf(const char *format, ...)
{
	char bf_ot[1024], *tobf, *arg_s, *(*int_f)(int), *(*s_f)(const char *);
	const char *p = format;
	unsigned int bf_i = 0, count = 0, ar_int;
	va_list args;

	va_start(args, format);
	if (!p || (p[0] == '%' && (!p[1] || (p[1] == ' ' && !p[2]))))
		return (-1);
	while (*format)
	{
		if (format[0] == '%' && format[1] != '\0')
		{
			format++, int_f = specifiers_int(*format);
			if (int_f != NULL)
			{
				ar_int = (*format == '%') ? '%' : va_arg(args, int), tobf = int_f(ar_int);
				tobf != NULL ? buffering(tobf, bf_ot, &bf_i, &count) : (void)0;
			}
			else if (int_f == NULL)
			{
				s_f = specifiers_str(*format);
				if (s_f != NULL)
				{
					arg_s = va_arg(args, char *), tobf = s_f(arg_s);
					tobf != NULL ? buffering(tobf, bf_ot, &bf_i, &count) : (void)0;
				}
				else if (s_f == NULL)
				{
					bf_ot[bf_i++] = '%', bf_ot[bf_i++] = *format, count += 2;
				}
			}
		}
		else if (*format != '%')
		{
			bf_ot[bf_i++] = *format, count++;
		}
		format++;
	}
	buffer_out(bf_ot, bf_i), va_end(args);
	return (count);
}

/**
 * buffer_out - output buffer
 *@buffer: the string to be written
 *@index: the index of the buffer
 */
void buffer_out(char *buffer, unsigned int index)
{
	size_t length = strlen(buffer);

	if (index < length)
	{
		length = index;
	}

	write(1, buffer, length);
}
