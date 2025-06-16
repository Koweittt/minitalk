/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:27:27 by abignals          #+#    #+#             */
/*   Updated: 2025/04/28 16:31:06 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	t;
	size_t	lit_len;

	lit_len = ft_strlen(lit);
	if (big == lit || lit_len == 0)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		t = 0;
		while (big[i + t] && lit[t] && (i + t < len) && big[i + t] == lit[t])
		{
			t++;
			if ((t == len && t == lit_len) || t == lit_len)
				return ((char *)(big + i));
		}
		i++;
	}
	return (0);
}
