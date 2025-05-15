#include "../../inc/minishell.h"

t_token	*new_token(void)
{
	t_token	*new_token;

	new_token = ft_calloc(sizeof(*new_token), 1);
	new_token->content = NULL;
	new_token->next = NULL;
	new_token->type = 0;
	return (new_token);
}

int	detect_token(char c, int target)
{
	if (target == SIMPLEQ)
		return (c != target);
	if (target == DOUBLEQ)
		return(c != target);
	if (ft_isalnum(target))
		return (ft_isalnum(c));
	if (target == '-')
		return(ft_isalnum(c));
	return (0);
}

// void	set_token_type(t_token *token, int target)
// {
// 	;
// }

int	fill_token(t_token *token, char *str)
{
	char	*buff;
	int		target;
	int		i;

	i = 0;
	target = str[0];
	i++;
	while (str[i] && detect_token(str[i], target))
		++i;
	if (target == DOUBLEQ || target == SIMPLEQ)
		buff = ft_substr(str, 1, i - 1);
	else
		buff = ft_substr(str, 0, i);
	token->type = CMD;
	token->content = buff;
	return (i + 1);
}

void	tokenizer(char *input, t_data *data)
{
	t_token	*token;
	int		i;

	i = 0;
	data->token = new_token();
	token = data->token;
	while (i < (int)ft_strlen(input) && input[i])
	{
		while (input[i] && ft_isspace(input[i]))
			++i;
		i += fill_token(token, &input[i]);
		token->next = new_token();
		token = token->next;
	}
	token = data->token;
	while (token->next && token->next->next)
		token = token->next;
	free(token->next);
	token->next = NULL;
}

int	cmd_size(t_token *token)
{
	int	i;

	if (!token)
		return (0);
	i = 0;
	while (token)
	{
		if (token->type == CMD || token->type == WORD)
			i++;
		token = token->next;
	}
	return (i);
}

void	token_to_cmd(t_data *data)
{
	int	i;
	t_token *token;

	i = 0;
	data->cmd = ft_calloc(sizeof(char *), cmd_size(data->token) + 1);
	token = data->token;
	while (token)
	{
		if (token->type == CMD || token->type == WORD)
		{
			data->cmd[i] = ft_calloc(sizeof(char), ft_strlen(token->content) + 1);
			data->cmd[i] = token->content;
		}
		token = token->next;
		++i;
	}
}

void	process(t_data *data)
{
	data->path = get_env_path(data->env, data->cmd[0]);
	execve(data->path, data->cmd, data->env);
}

//test main

int main(int argc, char **argv, char **env)
{
	(void)argc;
	t_data	*data;
	// t_token	*tmp;

	data = ft_calloc(sizeof(*data), 1);
	data->env = env;
	tokenizer(argv[1], data);
	// while (data->token)
	// {
	// 	printf("%s\n", data->token->content);
	// 	tmp = data->token;
	// 	data->token = data->token->next;
	// 	free(tmp);
	// }
	token_to_cmd(data);
	process(data);
}