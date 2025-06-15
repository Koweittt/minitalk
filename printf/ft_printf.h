/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:07:49 by abignals          #+#    #+#             */
/*   Updated: 2025/06/10 18:17:37 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *s1, ...);
void	ft_print_adr(unsigned long long int ptr, const char format);
int		ft_printf(char const *s1, ...);
int		ft_checkpourcentage(char s, va_list params);
int		ft_putnbr(long int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_puthex(unsigned int i, char const format);
int		ft_putpurcent(void);
int		ft_putadr(unsigned long long int ptr);

#endif //FT_PRINTF_UTILS_H
