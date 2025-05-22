#include "minishell.h"

void	set_path_to_parent(char *cwd, char **path)
{
	char	*last_slash;

	if (cwd == NULL || strcmp(cwd, "/") == 0)
	{
		*path = strdup("/");
	}
	else
	{
		*path = strdup(cwd);
		if (!(*path))
		{
			perror("strdup");
			return ;
		}
		last_slash = strrchr(*path, '/');
		if (last_slash && last_slash != *path)
			*last_slash = '\0';
	}
}

char	*brand_new_path(char *cwd, char *str)
{
	char	*new_path;
	size_t	cwd_len;
	size_t	str_len;

	if (!cwd)
	{
		perror("getenv");
		return (NULL);
	}
	cwd_len = strlen(cwd);
	str_len = strlen(str);
	new_path = malloc(cwd_len + str_len + 2);
	if (!new_path)
	{
		perror("malloc");
		return (NULL);
	}
	strcpy(new_path, cwd);
	new_path[cwd_len] = '/';
	strcpy(new_path + cwd_len + 1, str);
	return (new_path);
}

char	*check_and_create_new_path(DIR *dir, char *str, char *path)
{
	char	*cwd;

	if (dir)
	{
		closedir(dir);
		if (str[0] != '/')
		{
			cwd = getenv("PWD");
			path = brand_new_path(cwd, str);
		}
		else
			path = str;
	}
	else
	{
		perror("opendir");
		return (NULL);
	}
	return (path);
}

int	cd(char *str)
{
	char	*path;
	char	*old_pwd;
	int		ret;

	old_pwd = getenv("PWD");
	ret = handle_cd_home(&str);
	if (ret)
		return (ret);
	path = resolve_cd_path(str);
	if (!path)
		return (1);
	if (change_to_path(path))
		return (1);
	if (update_env(path, old_pwd))
		return (1);
	if (path != str)
		free(path);
	return (0);
}
