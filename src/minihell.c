#include "minishell.h"

int	main(int argc, char **argv)
{
	(void)argc;
	int			i;
	char 		*raw_input;
	char		*dir;
	t_env		*env_list;
	extern char	**environ;
	// t_data	data;

	env_list = env_init(environ);
	while (1)
	{
		i = 0;
		raw_input = readline("turboshell> ");
		// raw_input = readline_check(data);
		if (ft_strcmp(raw_input, "exit") == 0)
		{
			printf("%s\n", raw_input);
			free(raw_input);
			ft_exit(argv);
		}
		if (ft_strcmp(raw_input, "dir") == 0)
		{
			dir = getenv("PWD");
			printf("%s\n", dir);
			free(raw_input);
		}
		if (ft_strcmp(raw_input, "env") == 0)
		{
			env();
			free(raw_input);
		}
		cd(raw_input);
		if (ft_strcmp(raw_input, "pwd") == 0)
			ft_pwd();
		add_history(raw_input);
		free(raw_input);
	}
	rl_clear_history();
	return (0);
}
