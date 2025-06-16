/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:10:51 by abignals          #+#    #+#             */
/*   Updated: 2025/04/28 18:20:22 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memoryalloc(size_t size)
{
	void	*new;
	size_t	i;

	i = 0;
	new = (void *)malloc(size);
	if (!new)
		return (NULL);
	while (i < size)
	{
		*(unsigned char *)(new + i) = 0;
		i++;
	}
	return (new);
}

void	*ft_calloc(size_t count, size_t size)
{
	if (size != 0 && count > ((size_t) -1 / size))
		return (NULL);
	return (ft_memoryalloc(count * size));
}
