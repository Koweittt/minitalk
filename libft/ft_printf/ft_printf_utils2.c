/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:49:42 by abignals          #+#    #+#             */
/*   Updated: 2025/05/25 17:18:20 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_adr_len(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

int	ft_putadr(unsigned long long int ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	ft_print_adr(ptr, 'x');
	len += ft_adr_len(ptr);
	return (len);
}

int	ft_putnbr(long int n)
{
	unsigned int	pos;
	int				i;

	pos = n;
	i = 0;
	if (n < 0)
	{
		pos = -n;
		write(1, "-", 1);
		i++;
	}
	if (pos >= 10)
	{
		i += ft_putnbr(pos / 10);
		i += ft_putnbr(pos % 10);
	}
	else
	{
		i += ft_putchar(pos + '0');
	}
	return (i);
}

int	ft_puthex(unsigned int n, char const format)
{
	if (n == 0)
		return (write (1, "0", 1));
	ft_print_adr(n, format);
	return (ft_adr_len(n));
}

int	ft_putpurcent(void)
{
	write(1, "%", 1);
	return (1);
}
