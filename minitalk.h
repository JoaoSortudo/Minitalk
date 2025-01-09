/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-05 17:47:26 by jpires-n          #+#    #+#             */
/*   Updated: 2025-01-05 17:47:26 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

void	convert_signal(int signal);
void	send_signal(int pid, char *msg);
int		ft_atoi(const char *str);
int		ft_printf(const char *format, ...);

#endif