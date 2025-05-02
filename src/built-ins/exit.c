#include "minishell.h"

void	ft_exit(char **argv)
{
	int	code;

	code = (ft_atoi(argv[2]) % 256);
	//inserer fonction free
	exit (code);
}
