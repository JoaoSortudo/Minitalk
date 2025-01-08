/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-16 12:56:25 by jpires-n          #+#    #+#             */
/*   Updated: 2024-10-16 12:56:25 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (str[count])
		count++;
	write (1, str, count);
	return (count);
}

int	ft_print_void(void *ptr)
{
	unsigned long long	adress;
	int					count;

	adress = (unsigned long long)ptr;
	if (adress == 0)
		return (ft_print_string("(nil)"));
	count = ft_print_string("0x");
	count += ft_print_hex(adress, 0);
	return (count);
}
0xfa300b0102
64653123135465132154677653213463153465732