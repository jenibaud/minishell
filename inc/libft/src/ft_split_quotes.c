/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:41:19 by julifern          #+#    #+#             */
/*   Updated: 2025/05/02 17:38:01 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_quotes_len(char const *s, char c)
{
	int	i;
	int	word_len;
	int	quotes;

	i = 0;
	word_len = 0;
	quotes = 0;
	while (s[i])
	{
		
	}
	return (word_len);
}

static int	ft_word_quotes_counter(char const *s, char c)
{
	int	i;
	int	word_counter;

	i = 0;
	word_counter = 0;
	while (s[i])
	{
		if (s[i] == 22 || s[i] == 27)
		{
			while (s[i] != 22 && s[i] != 27)
			{
				i++;
			}
		}
		if ((s[i] == c && s[i + 1] != c) || s[i] == 0)
			word_counter++;
		i++;
	}
	return (word_counter);
}

static char	**ft_free_tabs(char **str, int j)
{
	while (--j)
		free(str[j]);
	free(str);
	return (NULL);
}

static char	**ft_splitter(char **str, char const *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		len = ft_word_len(&s[i], c);
		if (len == 0)
			break ;
		str[j] = ft_substr(s, i, len);
		if (!str[j])
			return (ft_free_tabs(str, j));
		i += len;
		j++;
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;

	if (!s)
		return (NULL);
	words = ft_word_counter(s, c);
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
