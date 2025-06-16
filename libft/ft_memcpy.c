/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:04:20 by abignals          #+#    #+#             */
/*   Updated: 2025/04/28 15:06:06 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstp;
	const char	*srcp;

	if (!dst && !src)
		return (0);
	if (n == 0 || (dst == src))
		return (dst);
	dstp = (char *)dst;
	srcp = (const char *)src;
	while (n != 0)
	{
		if (*dstp != *srcp)
			*dstp = *srcp;
		dstp++;
		srcp++;
		n--;
	}
	return (dst);
}
