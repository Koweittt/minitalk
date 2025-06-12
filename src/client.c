/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:23:09 by abignals          #+#    #+#             */
/*   Updated: 2025/06/12 11:11:41 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	ft_atoi(char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

void	send_messages(int PID, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(PID, SIGUSR1);
		else
			kill(PID, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	server_id;
	int	i;

	i = 0;
	if (argc == 3)
	{
		server_id = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_messages(server_id, argv[2][i]);
			i++;
		}
		send_messages(server_id, '\n');
	}
	else
		write(1, "Too much or too few arguments\n", 31);
	return (0);
}
