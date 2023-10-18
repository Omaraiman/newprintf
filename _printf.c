#include "main.h"

void output_content(char content[], int *content_index);

/**
 * _printf - Custom printf function
 * @input_format: input format.
 * Return: Number of characters printed.
 */
int _printf(const char *input_format, ...)
{
	int index, total_printed = 0, total_printed_chars = 0;
	int flag_values, width_value, precision_value, size_value, content_index = 0;
	va_list arg_list;
	char content[CONTENT_SIZE];

	if (input_format == NULL)
		return (-1);

	va_start(arg_list, input_format);

	for (index = 0; input_format && input_format[index] != '\0'; index++)
	{
		if (input_format[index] != '%')
		{
			content[content_index++] = input_format[index];
			if (content_index == CONTENT_SIZE)
				output_content(content, &content_index);
			total_printed_chars++;
		}
		else
		{
			output_content(content, &content_index);
			flag_values = fetch_flags(input_format, &index);
			width_value = fetch_width(input_format, &index, arg_list);
			precision_value = fetch_precision(input_format, &index, arg_list);
			size_value = fetch_size(input_format, &index);
			++index;
			total_printed = process_print(input_format, &index, arg_list, content,
				flag_values, width_value, precision_value, size_value);
			if (total_printed == -1)
				return (-1);
			total_printed_chars += total_printed;
		}
	}

	output_content(content, &content_index);

	va_end(arg_list);

	return (total_printed_chars);
}

/**
 * output_content - Outputs the contents of the content if it exist
 * @content: Array of characters
 * @content_index: Index at which to add next character, represents the length.
 */
void output_content(char content[], int *content_index)
{
	if (*content_index > 0)
		write(1, &content[0], *content_index);

	*content_index = 0;
}
