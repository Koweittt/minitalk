/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:23:09 by abignals          #+#    #+#             */
/*   Updated: 2025/06/10 16:32:25 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	res;
	int	count;
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

void	send_messages(int PID, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = -1;
		while (j++ < 8)
		{
			if ((unsigned char)(str[i] >> (7 - i) & 1) == 0)
				kill(PID, SIGUSR1);
			if ((unsigned char)(str[i] >> (7 - i) & 1) == 1)
				kill(PID, SIGUSR2);
			usleep(25);	
		}
		i++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(PID, SIGUSR1);
		usleep(25);	
	}
}

int	main(int argc, char **argv)
{
	int	server_id;


	if (argc == 3)
	{
		server_id = ft_atoi(argv[1]);
		if (!server_id)
		{
			write(1, "[ERROR] Wrong Argi\n", 18);
			return (0);
		}
		message = argv[2];
		if (!message)
		{
			write(1, "[ERROR] Wrong Arg\n" 18);
			return (0);
		}
		send_messages(server_id, message);
	}
	else
		write(1, "Too much or too few arguments\n", 31);
	return (0);
}

