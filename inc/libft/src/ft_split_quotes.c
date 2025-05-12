/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:41:19 by julifern          #+#    #+#             */
/*   Updated: 2025/05/05 17:24:00 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_quotes_counter(char *s, char c)
{
	int	i;
	int	word_counter;

	i = 0;
	word_counter = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
		{
			++i;
			while (s[i] != 34 && s[i] != 39)
			{
				++i;
			}
		}
		if (s[i + 1] == 0 || (s[i] == c && s[i + 1] != c))
			word_counter++;
		i++;
	}
	return (word_counter);
}

char	**ft_free_tabs(char **str, int j)
{
	while (--j)
		free(str[j]);
	free(str);
	return (NULL);
}

char	**ft_splitter(char **str, char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && (s[i] == 34 || s[i] == 39))
			str = quote_split(str, s, i, j);
		else
			str = normal_split(str, s, i, c, j);
		if (!str[j])
			ft_free_tabs(str, j);
		i += len_splitted(s, i, c);
		++j;
	}
	str[j] = 0;
	return (str);
}

char	**ft_split_quotes(char *s, char c)
{
	char	**str;
	int		words;

	if (!s)
		return (NULL);
	words = ft_word_quotes_counter(s, c);
	str = malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	if (words == 0)
	{
		str[0] = NULL;
		return (str);
	}
	str = ft_splitter(str, s, c);
	return (str);
}
