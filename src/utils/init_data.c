#include "../inc/minishell.h"

void	init_struct(t_data **data)
{
	while (*data)
	{
		(*data)->cmd = NULL;
		(*data)->infile = -1;
		(*data)->outfile = -1;
		(*data)->path = NULL;
		(*data)->pid = -1;
		++data;
	}
}

void	alloc_data(int data_size, t_data **data)
{
	int	i;

	i = 0;
	data = ft_calloc(sizeof(t_data), data_size);
	if (!data)
		return ;
	while (i < data_size)
	{
		data[i] = ft_calloc(sizeof(t_data), 1);
		if (!data[i] && i)
		{
			free(data[i - 1]);
			return ;
		}
		++i;
	}
	if (data_size > 1)
		data[data_size] = NULL;
	init_struct(data);
}
