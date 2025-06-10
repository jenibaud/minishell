#include "minishell.h"

int	pipes(t_data *data)
{
	if (data->token->type == PIPE)
		return (0);
	while (data->token->next)
	{
		if ((data->token->type == PIPE) && (data->token->next == NULL))
			return (0);
	}
	return (1);
}

int	redir_in(t_data *data)
{
	while (data->token->next)
	{
		if ((data->token->type == REDIR_IN) && (data->token->next == NULL))
			return (0);
	}
	return (1);
}

int	redir_out(t_data *data)
{
	while (data->token->next)
	{
		if ((data->token->type == REDIR_OUT) && (data->token->next == NULL))
			return (0);
	}
	return (1);
}
