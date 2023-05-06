/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:39:30 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/26 15:12:46 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Takes a type indicator and an argument list,
// Depending on the type indicator calls a corresponding printing function
static int	handle_arg(char type, va_list *args)
{
	if (type == 'c')
		return (print_char(va_arg(*args, int)));
	else if (type == 's')
		return (print_string(va_arg(*args, char *)));
	else if (type == 'p')
		return (print_pointer(va_arg(*args, void *)));
	else if (type == 'd' || type == 'i')
		return (print_int(va_arg(*args, int)));
	else if (type == 'u')
		return (print_unsigned(va_arg(*args, unsigned int)));
	else if (type == 'x')
		return (print_hex(va_arg(*args, unsigned int), 1));
	else if (type == 'X')
		return (print_hex(va_arg(*args, unsigned int), 0));
	else if (type == '%')
		return (print_char('%'));
	return (0);
}

// Depermines whether a character corresponds to one of the supported types
static int	is_valid_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

// Parses the template string and sends type indicators and an argument list
// to be handled by handle_arg()
static int	parse_args(const char *format, va_list *args)
{
	size_t	i;
	int		res_len;

	res_len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			res_len += print_char(format[i]);
		else if (is_valid_type(format[i + 1]))
		{
			res_len += handle_arg(format[i + 1], args);
			i++;
		}
		i++;
	}
	return (res_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res_len;

	va_start(args, format);
	res_len = parse_args(format, &args);
	va_end(args);
	return (res_len);
}
