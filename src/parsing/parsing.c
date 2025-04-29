#include "../inc/minishell.h"

void	parsing(char *rl, t_data **data, char **env)
{
	int		data_size;
	char	**args;

	args = NULL;
	if (!rl) // add isspace
		return ;
	if (ft_strcmp(rl, "|"))
	{
		args = ft_split(rl, '|');
		if (!args)
			return ;
	}
	else
		args[0] = rl; 
	data_size = (ft_count_array(args));
	alloc_data(data_size, data);
	data[0]->cmd = rl;
	data[0]->args = ft_split(rl, ' ');
	data[0]->path = get_env_path(env, data[0]->cmd);
	execve(data[0]->path, data[0]->args, env);
}