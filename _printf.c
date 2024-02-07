#include "main.h"
/**
 * _printf - function to use like printf function
 * @format: format string to be countered
 * Return: the number of bytes written
 */
int _printf(const char *format, ...)
{
	char bf_out[1024], *tobf, *arg_s, *(*int_funs)(int), *(*s_f)(const char *);
	unsigned int buf_i = 0, count = 0, i = 0, arg_int = 2;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++, int_funs = specifiers_int(*format);
			while (int_funs != NULL)
			{
				arg_int = (*format != '%') ? va_arg(args, int) : '%';
				tobf = (*format != '%') ? int_funs(arg_int) : for_module('%');
				for (i = 0; tobf[i] != '\0'; i++, count++)
					bf_out[buf_i++] = tobf[i];
				free(tobf), buffer_out(bf_out, buf_i), buf_i = 0;
			}
			s_f = specifiers_str(*format);
			while (s_f != NULL)
			{
				arg_s = va_arg(args, char *), tobf = s_f(arg_s);
				for (i = 0; tobf[i]; i++, count++)
					bf_out[buf_i++] = tobf[i];
				free(tobf);
			}
			if (int_funs == NULL && s_f == NULL)
				bf_out[buf_i++] = '%', bf_out[buf_i++] = *format, count += 2;
		}
		else if (*format != '%')
		{
			bf_out[buf_i++] = *format;
			count++;
		}
		else
			return (-1);
		format++;
	}
	buffer_out(bf_out, buf_i), va_end(args);
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
