#include "minishell.h"

extern char **environ;

int	env(void)
{
	char	**env;
	env = environ;
	while (*env != NULL)
	{
        printf("%s\n", *env);
		env++;
    }
    return 0;
}
