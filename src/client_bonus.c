/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:27:30 by abignals          #+#    #+#             */
/*   Updated: 2025/06/12 13:05:03 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"

static int	ft_atoi(char *str)
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

static void	ft_confirm(int signum)
{
	if (signum == SIGUSR1)
		printf("Signal Recu\n");
	else
		printf("Signal Recu\n");
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
			signal(SIGUSR1, ft_confirm);
			signal(SIGUSR2, ft_confirm);
			send_messages(server_id, argv[2][i]);
			i++;
		}
		send_messages(server_id, '\n');
	}
	else
		write(1, "Too much or too few arguments\n", 31);
	return (0);
}
