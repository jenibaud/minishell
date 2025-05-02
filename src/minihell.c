#include "minishell.h"

g_signal = 0;

char	*readline_check(t_data **data)
{
	char	*rl;

	rl = readline("turboshell> ");
	// rajouter signaux
	return (rl);
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;
	char	*raw_input;

	(void)ac;
	(void)av;
	data = init_data(data);
	while (1)
	{
		raw_input = readline_check(data);
		if (ft_strcmp(raw_input, "exit") == 0)
		{
			free(raw_input);
			break;
		}
		add_history(raw_input);
		data->args = valid_input(raw_input);
		handle_input(data);
		printf("%s\n", raw_input);
		free(raw_input);
	}
	return (0);
}
