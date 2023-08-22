#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @output_buffer: Array of characters
 * @output_buffer_index: a function
 */
void print_buffer(char output_buffer[], int *output_buffer_index);

/**
 * custom_printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int custom_printf(const char *format, ...)
{
	int i, total_printed = 0, printed_chars = 0;
	int flags, width, precision, size, output_buffer_index = 0;
	va_list args_list;
	char output_buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args_list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			output_buffer[output_buffer_index++] = format[i];
			if (output_buffer_index == BUFF_SIZE)
				print_buffer(output_buffer, &output_buffer_index);
			printed_chars++;
		}
		else
		{
			print_buffer(output_buffer, &output_buffer_index);
			flags = get_flags_custom(format, &i);
			width = get_width_custom(format, &i, args_list);
			precision = get_precision_custom(format, &i, args_list);
			size = get_size_custom(format, &i);
			++i;
			total_printed = handle_print_custom(format, &i, args_list, output_buffer,
				flags, width, precision, size);
			if (total_printed == -1)
				return (-1);
			printed_chars += total_printed;
		}
	}

	print_buffer(output_buffer, &output_buffer_index);

	va_end(args_list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @output_buffer: Array of characters
 * @output_buffer_index: Index at whi
 */
void print_buffer(char output_buffer[], int *output_buffer_index)
{
	if (*output_buffer_index > 0)
		write(1, &output_buffer[0], *output_buffer_index);

	*output_buffer_index = 0;
}

