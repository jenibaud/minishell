/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spit_quotes_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:15:18 by julifern          #+#    #+#             */
/*   Updated: 2025/05/06 14:08:10 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_quote_nb(char *s)
{
	int	i;
	int	quote_nb;

	i = 0;
	quote_nb = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
			++quote_nb;
		++i;
	}
	return (quote_nb);
}

int		len_splitted(char *s, int i, char c)
{
	int	len;
	int	quotes;

	quotes = get_quote_nb(s);
	len = 1;
	if (s[i] == 34 || s[i] == 39)
	{
		--quotes;
		while (s[i] && quotes > 0)
		{
			i++;
			if (s[i] && (s[i] == 34 || s[i] == 39))
				--quotes;
			++len;
		}
	}
	else
	{
		while (s[i++] && s[i] != c)
			++len;
	}
	return (len);
}

char	**normal_split(char **str, char *s, int i, char c, int j)
{
	int		len;
	int		start;

	start = i;
	len = 0;
	while (s[i] && s[i] != c)
	{
		++len;
		++i;
	}
	str[j] = ft_substr(s, start, len);
	return (str);
}


char	**quote_split(char **str, char *s, int i, int j)
{
	int		len;
	int		start;
	int		quotes;

	quotes = get_quote_nb(s);
	start = i;
	len = 0;
	while (s[i] && quotes > 0)
	{
		if (s[i] && (s[i] == 34 || s[i] == 39))
			--quotes;
		++len;
		++i;
	}
	str[j] = ft_substr(s, start, len);
	return (str);
}
