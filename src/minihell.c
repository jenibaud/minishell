#include "../inc/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	**data;
	char *rl;

	(void)ac;
	(void)av;
	data = NULL;
	while (1)
	{
		rl = readline("turboshell> ");
		if (ft_strcmp(rl, "exit") == 0)
		{
			free(rl);
			break;
		}
		add_history(rl);
		parsing(rl, data, env);
		printf("%s\n", rl);
		free(rl);
	}
	return (0);
}
