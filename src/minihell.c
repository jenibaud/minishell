#include "../inc/minishell.h"

int	main(char **env)
{
	char *rl;

	rl = readline("turboshell> ");
	printf("%s", rl);
	return (0);
}
