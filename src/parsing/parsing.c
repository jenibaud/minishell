#include "../inc/minishell.h"

// void	get_cmd(char **args, int data_size, t_data **data)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_count_array(args) > 1)
// 	{
// 		while (*data)
// 		{
// 			(*data)->cmd = args[i++];
// 			++data;
// 		}
// 	}
// }

// int	is_block(char *rl, int i)
// {
// 	while (rl[i])
// 	{
// 		if (rl[i] == '|')
// 			break;
// 		i++;
// 	}
// 	return (i);
// }

// int	get_block_nb(char *rl, t_data **data)
// {
// 	int	block_nb;
// 	int	i;

// 	block_nb = 0;
// 	i = 0;
// 	while (rl[i])
// 	{
// 		i = is_block(&rl[i], i);
// 		if (i == ft_strlen(rl))
// 			return (block_nb + 1);
// 		while (ft_isspace(rl[i]))
// 			++i;
// 		if (rl[i] != 22 && rl[i] != 27)
// 			++block_nb;
// 		++i;
// 	}
// 	return (block_nb);
// }

// void	parsing(char *rl, t_data **data, char **env)
// {
// 	int		data_size;
// 	char	**args;

// 	args = NULL;
// 	if (!rl) // add isspace
// 		return ;
// 	if (ft_strcmp(rl, "|"))
// 	{
// 		args = ft_split(rl, '|');
// 		if (!args)
// 			return ;
// 	}
// 	else
// 		args[0] = rl; 
// 	data_size = (ft_count_array(args)) + 1; // +1 to have space for NULL tab
// 	alloc_data(data_size, data);
// 	get_args(rl, data);
// 	// data[0]->cmd = rl;
// 	// data[0]->args = ft_split(rl, ' ');
// 	// data[0]->path = get_env_path(env, data[0]->cmd);
// }

void	handle_input(t_data *data)
{
	(void)data;
}

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
		if (rl[i] == "/" || rl[i] == ";" || (rl[i] == "|" && rl[i + 1] == "|"))
			return (NULL); // syntax error message
	}
	array = ft_split(rl, " ");
	if (!array)
		return (NULL); // handle empty string
	else
		return (array);
}
