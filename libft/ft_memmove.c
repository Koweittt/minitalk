/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:06:37 by abignals          #+#    #+#             */
/*   Updated: 2025/04/28 15:13:08 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dstp;
	const char	*srcp;

	if (src == dst)
		return (dst);
	dstp = (char *)dst;
	srcp = (const char *)src;
	if (srcp < dstp && srcp + len > dstp)
		while (len--)
			*(dstp + len) = *(srcp + len);
	else
	{
		while (len--)
		{
			*dstp = *srcp;
			srcp++;
			dstp++;
		}
	}
	return (dst);
}
