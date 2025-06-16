/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:12:56 by abignals          #+#    #+#             */
/*   Updated: 2025/04/28 16:20:46 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	ch;
	char			*pstr;
	int				i;

	ch = c;
	i = ft_strlen(str);
	pstr = (char *)str + i;
	if (ch == '\0')
		return (pstr++);
	while (pstr >= str)
	{
		if (*pstr == ch)
			return (pstr);
		pstr--;
	}
	pstr = NULL;
	return (pstr);
}
