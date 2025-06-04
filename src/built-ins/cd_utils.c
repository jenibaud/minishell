#include "minishell.h"

int	handle_cd_home(char **str)
{
	if (*str == NULL || strcmp(*str, "~") == 0)
	{
		*str = getenv("HOME");
		if (*str == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return (1);
		}
	}
	return (0);
}

int	change_to_path(char *path)
{
	if (chdir(path) == -1)
	{
		perror("chdir");
		free(path);
		return (1);
	}
	return (0);
}

int	update_env(char *path, char *old_pwd)
{
	if (setenv("PWD", path, 1) == -1)
	{
		perror("setenv");
		free(path);
		return (1);
	}
	if (setenv("OLDPWD", old_pwd, 1) == -1)
	{
		perror("setenv (OLDPWD)");
		free(path);
		return (1);
	}
	return (0);
}

char	*resolve_cd_path(char *str)
{
	char	*cwd;
	DIR		*dir;
	char	*path;

	if (!strcmp(str, ".."))
	{
		cwd = getenv("PWD");
		path = NULL;
		set_path_to_parent(cwd, &path);
	}
	else
	{
		dir = opendir(str);
		path = check_and_create_new_path(dir, str, NULL);
	}
	return (path);
}
