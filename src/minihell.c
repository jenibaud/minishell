#include "minishell.h"

// char	*readline_check(t_data *data)
// {
// 	char	*rl;

// 	// rajouter signaux
// 	return (rl);
// }

int	main(int ac, char **av, char **env)
{
	// t_data	*data;
	char	*raw_input;
	char	**array;
	int		i;
	
	(void)env;
	(void)ac;
	(void)av;
	// data = init_data(data);
	while (1)
	{
		i = 0;
		raw_input = readline("turboshell> ");
		// raw_input = readline_check(data);
		if (ft_strcmp(raw_input, "exit") == 0)
		{
			free(raw_input);
			break;
		}
		// add_history(raw_input);
		
		// data->args = valid_input(raw_input);
		// handle_input(data);
		while (array[i])
		{
			printf("%s\n", array[i]);
			free(array[i]);
			array[i] = NULL;
			i++;
		}
		free(raw_input);
	}
	return (0);
}
