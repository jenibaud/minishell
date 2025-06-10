#include "../../inc/minishell.h"

static void	print_token(t_data *data)
{
	while (data->token)
	{
		printf("token : %s, type : ", data->token->content);
		printf("%d\n", data->token->type);
		data->token = data->token->next;
	}
}

void	skip_to_pipe()
{

}

t_token	*new_token(void)
{
	t_token	*new_token;
	
	new_token = ft_calloc(sizeof(*new_token), 1);
	new_token->content = NULL;
	new_token->next = NULL;
	new_token->type = 0;
	return (new_token);
}

int	is_meta_character(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	detect_token_end(char c, int target)
{
	if (ft_isalnum(target) || target == SIMPLEQ || target == DOUBLEQ)
		return (!is_meta_character(c) && c != 0);
	if (target == '|')
		return (c == '|');
	if (target == '<')
		return (c == target);
	if (target == '>')
		return (c == target);
	return (0);
}

void	set_token_type(char *input, t_token *token, int target)
{
	token->type = WORD;
	if (target == '|')
		token->type = PIPE;
	else if (target == '<')
	{
		if (input[1] == '<')
			token->type = HEREDOC;
		else
			token->type = REDIR_IN;
	}
	else if (target == '>')
	{
		if (input[1] == '>')
			token->type = APPEND;
		else
			token->type = REDIR_OUT;
	}
}

int	fill_token(t_token *token, char *input)
{
	char	*buff;
	int		target;
	int		i;

	i = 0;
	target = input[0];
	set_token_type(input, token, target);
	i++;
	while (input[i] && detect_token_end(input[i], target))
		++i;
	buff = ft_substr(input, 0, i);
	token->content = buff;
	return (i);
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
		if (token->type == WORD)
			i++;
		token = token->next;
	}
	return (i);
}

// void	token_to_cmd(t_data *data)
// {
// 	int		i;
// 	int		pipe_count;
// 	t_token *token;

// 	i = 0;
// 	pipe_count = data->pipe_nmb;
// 	token = data->token;
// 	while (token)
// 	{
// 		token->cmd = ft_split(token->content, ' ');
// 		token = token->next;
// 	}
// }

// void	process(t_data *data)
// {
// 	data->path = get_env_path(data->env, data->token->cmd[0]);
// 	execve(data->path, data->token->cmd, data->env);
// }

//test main

int main(int argc, char **argv, char **env)
{
	(void)argc;
	t_data	*data;
	t_token	*tmp;

	data = ft_calloc(sizeof(*data), 1);
	data->env = env;
	tokenizer(argv[1], data);
	while (data->token)
	{
		printf("token : %s, type : ", data->token->content);
		printf("%d\n", data->token->type);
		tmp = data->token;
		data->token = data->token->next;
		free(tmp);
	}
	print_token(data);
	// token_to_cmd(data);
	// process(data);
}