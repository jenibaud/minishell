#include "minishell.h"

static void	export_set_variable(char *arg, t_env **env)
{
	char	*equal;
	char	*key;
	char	*value;
	int		len;

	equal = ft_strchr(arg, '=');
	if (!equal)
	{
		env_set(env, arg, NULL);
		return ;
	}
	len = equal - arg;
	key = ft_substr(arg, 0, len);
	value = ft_strdup(equal + 1);
	if (!key || !value)
		return ;
	env_set(env, key, value);
	free(key);
	free(value);
}

void	builtin_export(char **args, t_env **env)
{
	int	i;

	if (!args[1])
	{
		export_print(*env);
		return ;
	}
	i = 1;
	while (args[i])
	{
		if (!is_valid_identifier(args[i]))
			printf("minishell: export: `%s`: not a valid identifier\n", args[i]);
		else
			export_set_variable(args[i], env);
		i++;
	}
}

