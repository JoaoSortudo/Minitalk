/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_functions2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-17 15:08:33 by jpires-n          #+#    #+#             */
/*   Updated: 2024-10-17 15:08:33 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_nbr(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count += ft_print_char('-');
		if (nb == -2147483648)
		{
			count += ft_print_char('2');
			nb = -147483648;
		}
		nb *= -1;
	}
	if (nb >= 10)
		count += ft_print_nbr(nb / 10);
	count += ft_print_char((nb % 10) + '0');
	return (count);
}

int	ft_print_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_print_unsigned(nb / 10);
	count += ft_print_char((nb % 10) + '0');
	return (count);
}

int	ft_print_hex(unsigned long long number, int uppercase)
{
	char	*charset;
	int		count;

	if (uppercase)
		charset = "0123456789ABCDEF";
	else
		charset = "0123456789abcdef";
	count = 0;
	if (number >= 16)
	{
		count += ft_print_hex(number / 16, uppercase);
	}
	count += ft_print_char(charset[number % 16]);
	return (count);
}
