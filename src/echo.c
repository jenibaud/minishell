#include "minishell.h"

void	ft_echo(t_data *data)
{
	int	i;

	i = 2;
	if (!ft_strnstr(data->args[1], "-n", 2))
		i = 1;
	if (!data->args)
		printf("\n");
	if (!data->args[0])
		printf("\n");
	while (data->args[i])
	{
		printf("%s", data->args[i]);
		i++;
	}
	if (!ft_strnstr(data->args[1], "-n", 2))
		printf("\n");
}

void	ft_pwd(void)
{
	char	buf[4096];

	if(getcwd(buf, 4096) != NULL)
		printf("%s\n", buf);
	else
		printf("\n");
}
