#include "minishell.h"

void	ft_exit(char **argv)//remplacer argv par le vrai code
{
	int	code;

	code = (ft_atoi(argv[2]) % 256); //remplacer argv[2] par le vrai code
	//inserer fonction free
	exit (code);
}
