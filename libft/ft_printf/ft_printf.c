/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:36:23 by abignals          #+#    #+#             */
/*   Updated: 2025/06/04 09:59:32 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkpourcent(const char *s1, va_list Params)
{
	int	i;

	i = 0;
	if (s1[i] == '%')
	{
		if (s1[i + 1] == 'c')
			return (ft_putchar(va_arg(Params, int)));
		else if (s1[i + 1] == 's')
			return (ft_putstr(va_arg(Params, char *)));
		else if (s1[i + 1] == 'p')
			return (ft_putadr(va_arg(Params, unsigned long long int)));
		else if (s1[i + 1] == 'd' || s1[i + 1] == 'i')
			return (ft_putnbr(va_arg(Params, int)));
		else if (s1[i + 1] == 'u')
			return (ft_putnbr(va_arg(Params, unsigned int)));
		else if (s1[i + 1] == 'x')
			return (ft_puthex(va_arg(Params, unsigned int), 'x'));
		else if (s1[i + 1] == 'X')
			return (ft_puthex(va_arg(Params, unsigned int), 'X'));
		else if (s1[i + 1] == '%')
			return (ft_putpurcent());
	}
	return (0);
}

int	ft_printf(char const *s1, ...)
{
	va_list	params;
	int		tot;
	int		i;

	if (!s1)
		return (-1);
	tot = 0;
	i = 0;
	va_start(params, s1);
	while (s1[i])
	{
		if (s1[i] == '%')
		{
			tot += checkpourcent(&s1[i], params);
			i++;
		}
		else
			tot += ft_putchar(s1[i]);
		i++;
	}
	va_end(params);
	return (tot);
}

/*int	main(void)
{
	int	n;
	char	*str = "test";

	n = ft_printf(0);
	ft_printf("%d", n);
}*/
