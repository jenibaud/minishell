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
	return (0);
}

void	set_token_type(t_token *token, int target)
{
	;
}

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
	buff = ft_substr(str, 1, i - 1);
	buff[i] = 0;
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

//test main

int main(int argc, char **argv)
{
	(void)argc;
	t_data	*data;
	t_token	*tmp;
 
	data = ft_calloc(sizeof(*data), 1);
	tokenizer(argv[1], data);
	while (data->token)
	{
		printf("%s\n", data->token->content);
		tmp = data->token;
		data->token = data->token->next;
		free(tmp);
	}
}