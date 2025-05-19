#include "../inc/minishell.h"

int	main(int argc, char **argv)
{
	(void)argc;
	char 	*rl;
	char	*dir;
	// t_data	data;

	while (1)
	{
		rl = readline("turboshell> ");
		if (ft_strcmp(rl, "exit") == 0)
		{
			printf("%s\n", rl);
			free(rl);
			ft_exit(argv);
		}
		if (ft_strcmp(rl, "dir") == 0)
		{
			dir = getenv("PWD");
			printf("%s\n", dir);
			free(rl);
		}
		if (ft_strcmp(rl, "env") == 0)
		{
			env();
			free(rl);
		}
		cd(rl);
		if (ft_strcmp(rl, "pwd") == 0)
			ft_pwd();
		add_history(rl);
		free(rl);
	}
	rl_clear_history();
	return (0);
}
