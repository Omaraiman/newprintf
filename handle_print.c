#include "main.h"
/**
 * handle_prnt - Prints an argument based on its type
 * @frmt: Formatted string in which to print the arguments.
 * @lst: List of arguments to be printed.
 * @idx: Index.
 * @buf: Buffer array to handle print.
 * @flgs: Calculates active flags
 * @wdth: Width
 * @prec: Precision specification
 * @sz: Size specifier
 * Return: 1 or 2;
 */
int handle_prnt(const char *frmt, int *idx, va_list lst, char buf[],
	int flgs, int wdth, int prec, int sz)
{
	int i, unknown_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (frmt[*idx] == fmt_types[i].fmt)
			return (fmt_types[i].fn(lst, buf, flgs, wdth, prec, sz));

	if (fmt_types[i].fmt == '\0')
	{
		if (frmt[*idx] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (frmt[*idx - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (wdth)
		{
			--(*idx);
			while (frmt[*idx] != ' ' && frmt[*idx] != '%')
				--(*idx);
			if (frmt[*idx] == ' ')
				--(*idx);
			return (1);
		}
		unknown_len += write(1, &frmt[*idx], 1);
		return (unknown_len);
	}
	return (printed_chars);
}
