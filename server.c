/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:48:48 by abignals          #+#    #+#             */
/*   Updated: 2025/06/10 17:33:35 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Printf/printf.h"
#include "minitalk.h"


void	main_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		
	}
	if (signum == SIGUSR2)
	{
		
	}
}

int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		ft_printf("WRONG FORMAT\n SERVER REQUIRES NO ARGUMENT\n");
		return (0);
	}
	ft_printf("%d", getpid()); 
	while (1)
	{
		signal(SIGUSR1, main_handler);
		signal(SIGUSR2, main_handler);
		pause();
	}
	return (0);
}


