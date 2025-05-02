#include "minishell.h"

void	init_struct(t_data *data)
{
	data->cmd = NULL;
	data->infile = 0;
	data->outfile = 1;
	data->path = NULL;
	data->pid = NULL;
}

void	free_data(t_data *data)
{
	
}