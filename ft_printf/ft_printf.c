/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-16 15:20:17 by jpires-n          #+#    #+#             */
/*   Updated: 2024-10-16 15:20:17 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_conversions(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_void(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(args, int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		fmt_len;
	va_list	args;

	count = 0;
	fmt_len = 0;
	va_start(args, format);
	while (format[count])
	{
		if (format[count] == '%')
		{
			count++;
			fmt_len += ft_print_conversions(format[count], args);
		}
		else
			fmt_len += ft_print_char(format[count]);
		count++;
	}
	va_end(args);
	return (fmt_len);
}
