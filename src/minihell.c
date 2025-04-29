#include "../inc/minishell.h"

int	main(void)
{
	char *rl;
	is_running = 1;

	while (is_running != 0)
	{
		rl = readline("turboshell> ");
		if (ft_strcmp(rl, "exit") == 0)
		{
			free(rl);
			break;
		}
		add_history(rl);
		printf("%s\n", rl);
		free(rl);
	}
	return (0);
}
