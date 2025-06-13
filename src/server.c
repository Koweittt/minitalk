/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:48:48 by abignals          #+#    #+#             */
/*   Updated: 2025/06/13 11:47:29 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include "../Printf/ft_printf.h"

void	main_handler(int signum)
{
	static int	bit;
	static int	i;

	if (signum == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		i = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{	
	(void)argv;
	if (argc != 1)
	{
		ft_printf("WRONG FORMAT\nSERVER REQUIRES NO ARGUMENT\n");
		return (0);
	}
	ft_printf("%d\n", getpid());
	while (argc == 1)
	{
		signal(SIGUSR1, main_handler);
		signal(SIGUSR2, main_handler);
		pause();
	}
	return (0);
}
