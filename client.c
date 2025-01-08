/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpires-n <jpires-n@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-05 17:53:41 by jpires-n          #+#    #+#             */
/*   Updated: 2025-01-05 17:53:41 by jpires-n         ###   ########.rio      */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
//este programa vai enviar uma mensagem para o servidor, utilizando o PID referente ao mesmo, vamos usar uma função que recebe o PID do servidor e uma string contendo a mensagem passada:
void	send_signal(int pid, char *msg)
{
	int	i;
	int	byte;

	i = 0;
	while (msg[i])
	{
		byte = 7;
		while (byte >= 0)
		{
			if (msg[i] & (1 << byte))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			byte--;
			usleep(100);
		}
		i++;
	}
	byte = 7;
	while (byte >= 0)
	{
		kill(pid, SIGUSR2);
		byte--;
		usleep(100);
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	symb;

	result = 0;
	symb = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			symb *= -1;
		i++;
		if (str[i] == '+' || str[i] == '-')
			return (0);
	}
	while (str[i] > 47 && str[i] < 58)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * symb);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	send_signal(ft_atoi(argv[1]), argv[2]);
	return (0);
}
