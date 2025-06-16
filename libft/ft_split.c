/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abignals <abignals@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:58:06 by abignals          #+#    #+#             */
/*   Updated: 2025/05/03 16:58:07 by abignals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	count;
	int	in_word;

	if (c == '\0')
		return (*str != '\0');
	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (str[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	**ft_fill_tab(char **tab, const char *str, char c)
{
	int	i;
	int	t;
	int	start;

	i = 0;
	t = 0;
	while (str[i] && t < ft_count_words(str, c))
	{
		while (str[i] == c)
			i++;
		start = i;
		while (str[i] && str[i] != c)
			i++;
		tab[t] = malloc(i - start + 1);
		if (!tab[t])
		{
			while (t-- > 0)
				free(tab[t]);
			return (NULL);
		}
		ft_strlcpy(tab[t], &str[start], i - start + 1);
		t++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	tab = malloc((word_count + 1) * sizeof(char *));
	if (!tab)
	{
		return (NULL);
	}
	if (!ft_fill_tab(tab, s, c))
	{
		free(tab);
		return (NULL);
	}
	tab [word_count] = NULL;
	return (tab);
}

/*int	main(int argc, char **argv)
{
	char	**tab;
	int		i;

	i = 0;
	{
		tab = ft_split(argv[1],);
		while (tab[i])
		{
			printf("%s\n", tab[i]);
			i++;
		}
	}
	return (0);
}*/
