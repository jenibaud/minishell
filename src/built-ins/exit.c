#include "minishell.h"

void	ft_exit(t_data *data)
{
	int	code;

	code = ft_atoi(data->exit_code);
	exit (code);
}
