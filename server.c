/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-05 17:53:36 by jpires-n          #+#    #+#             */
/*   Updated: 2025-01-05 17:53:36 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_signal(int signal)
{
	static char	byte = '\0';
	static int	count = 7;

	if (signal == SIGUSR1)
		byte = byte | (1 << count--);
	else if (signal == SIGUSR2)
		count--;
	if (count == -1)
	{	
		if (byte)
			ft_printf("%c", byte);
		else
			ft_printf("\n");
		count = 7;
		byte = '\0';
	}
}

int	main(void)
{
	ft_printf("%i\n", getpid());
	signal(SIGUSR1, convert_signal);
	signal(SIGUSR2, convert_signal);
	while (1)
		;
	return (0);
}
