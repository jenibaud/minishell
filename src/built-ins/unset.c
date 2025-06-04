#include "minishell.h"

void	env_remove(t_env **env, char *key)
{
	t_env	*curr;
	t_env	*prev;

	curr = *env;
	prev = NULL;
	while (curr)
	{
		if (ft_strcmp(curr->key, key) == 0)
		{
			if (prev)
				prev->next = curr->next;
			else
				*env = curr->next;
			free(curr->key);
			free(curr->value);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

int	is_valid_unset_key(char *str)
{
	int	i;

	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	builtin_unset(char **args, t_env **env)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (!is_valid_unset_key(args[i]))
			printf("minishell: unset: `%s`: not a valid identifier\n", args[i]);
		else
			env_remove(env, args[i]);
		i++;
	}
}

