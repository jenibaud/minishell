#include "minishell.h"

void	ft_pwd(void)
{
	char	buf[4096];

	if(getcwd(buf, 4096) != NULL)
		printf("%s\n", buf);
	else
		printf("\n");
}
