/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:10:02 by abignals          #+#    #+#             */
/*   Updated: 2025/04/28 16:15:42 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (NULL);
}
