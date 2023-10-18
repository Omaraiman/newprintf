#include "main.h"

void output_buffer(char buf[], int *buf_idx);

/**
 * _printf - Custom printf function
 * @fmt: format string.
 * Return: Number of characters printed.
 */
int _printf(const char *fmt, ...)
{
	int j, print_result = 0, total_chars = 0;
	int flgs, wdth, prec, sz, buf_idx = 0;
	va_list args;
	char buf[BUFF_SIZE];

	if (fmt == NULL)
		return (-1);

	va_start(args, fmt);

	for (j = 0; fmt && fmt[j] != '\0'; j++)
	{
		if (fmt[j] != '%')
		{
			buf[buf_idx++] = fmt[j];
			if (buf_idx == BUFF_SIZE)
				output_buffer(buf, &buf_idx);
			total_chars++;
		}
		else
		{
			output_buffer(buf, &buf_idx);
			flgs = get_flags(fmt, &j);
			wdth = get_width(fmt, &j, args);
			prec = get_precision(fmt, &j, args);
			sz = get_size(fmt, &j);
			++j;
			print_result = handle_print(fmt, &j, args, buf,
				flgs, wdth, prec, sz);
			if (print_result == -1)
				return (-1);
			total_chars += print_result;
		}
	}

	output_buffer(buf, &buf_idx);

	va_end(args);

	return (total_chars);
}

/**
 * output_buffer - Outputs the contents of the buffer if it exists
 * @buf: Character array
 * @buf_idx: Index at which to add next character, represents the length.
 */
void output_buffer(char buf[], int *buf_idx)
{
	if (*buf_idx > 0)
		write(1, &buf[0], *buf_idx);

	*buf_idx = 0;
}
