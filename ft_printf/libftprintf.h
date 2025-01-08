/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-16 16:26:58 by jpires-n          #+#    #+#             */
/*   Updated: 2024-10-16 16:26:58 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_string(char *str);
int	ft_print_nbr(int nb);
int	ft_print_void(void *ptr);
int	ft_print_unsigned(unsigned int nb);
int	ft_print_hex(unsigned long long number, int uppercase);

#endif