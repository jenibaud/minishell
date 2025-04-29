#include "../inc/minishell.h"

char	*search_path(char **path, char *cmd)
{
	char	*test_path;
	size_t	i;

	test_path = NULL;
	i = 0;
	while (path[i])
	{
		test_path = ft_strjoin(path[i], cmd);
		if (!test_path)
			return (NULL);
		if (access(test_path, F_OK | X_OK) == 0)
		{
			free(cmd);
			return (test_path);
		}
		i++;
		free(test_path);
		test_path = NULL;
	}
	free(cmd);
	return (NULL);
}

char	*get_env_path(char **env, char *cmd)
{
	int		i;
	char	**path;
	char	*tmp;

	i = 0;
	if (cmd && access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (ft_strlen(env[i]) < 6)
		return (NULL); // error message
	tmp = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
	path = ft_split(tmp, ':');
	i = 0;
	free(tmp);
	tmp = search_path(path, ft_strjoin("/", cmd));
	ft_free_array(path, ft_count_array(path));
	return (tmp);
}