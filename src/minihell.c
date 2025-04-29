#include "../inc/minishell.h"

int	main(void)
{
	char *rl;

	while (1)
	{
		rl = readline("turboshell> ");
		if (ft_strcmp(rl, "exit") == 0)
		{
			free(rl);
			break;
		}
		if (ft_strcmp(rl, "pwd") == 0)
			ft_pwd();
		add_history(rl);
		free(rl);
	}
	return (0);
}
