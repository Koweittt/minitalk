/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:45:36 by abignals          #+#    #+#             */
/*   Updated: 2025/05/25 16:57:58 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &(s[i]), 1);
		i++;
	}
	return (i);
}

void	ft_print_adr(unsigned long long int ptr, const char format)
{
	if (ptr >= 16)
	{
		ft_print_adr(ptr / 16, format);
		ft_print_adr(ptr % 16, format);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar(ptr + 48);
		else if (format == 'x')
			ft_putchar((ptr - 10) + 'a');
		else if (format == 'X')
			ft_putchar((ptr - 10) + 'A');
	}
}
