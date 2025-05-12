#include "../inc/minishell.h"

void	handle_input(t_data *data)
{
	// wip
	(void)data;
}

//probablement a scrap

int	count_quotes(char *rl, int i)
{
	int		quotes;
	char	c;

	quotes = 2;
	while (rl[i])
	{
		if (rl[i] == 22 || rl[i] == 27)
		{
			c = rl[i];
			++i;
			while (rl[i] && rl[i] != c)
				++i;
			++quotes;
		}
		++i;
	}
	return (quotes);
}

char	**valid_input(char *rl)
{
	char **array;
	int	i;

	array = NULL;
	i = 0;
	if (!rl)
		return (NULL); // handle empty string
	if (count_quotes(rl, 0) % 2)
		return (NULL); // syntax error message
	while (rl[i])
	{
		while (rl[i] && ft_isspace(rl[i]))
			i++;
		if (!rl[i])
			break ;
		if (rl[i] == '/' || rl[i] == ';' || (rl[i] == '|' && rl[i + 1] == '|'))
			return (NULL); // syntax error message
	}
	array = ft_split_quotes(rl, ' ');
	if (!array)
		return (NULL); // handle empty string
	else
		return (array);
}
