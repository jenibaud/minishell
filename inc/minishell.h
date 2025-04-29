#ifndef MINISHELL_H
# define MINISHELL_H

/*##############################################*/
/*					Includes					*/
/*##############################################*/

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <utmp.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include <stdbool.h>
# include "libft/inc/libft.h"

/*##############################################*/
/*					Defines						*/
/*##############################################*/

# define CODE_CTRL_C 130;
# define CODE_NOT_FOUND 127;
# define CODE_NOT_EXEC 126;
# define CODE_ERROR 1;
# define CODE_BADFD 0;

/*##############################################*/
/*					Structs						*/
/*##############################################*/

typedef struct	s_env
{
	char	**export;
	char 	**env;
}	t_env;

typedef struct	s_data
{
	char	*cmd;
	char	**args;
	char	*path;
	int		infile;
	int		outfile;
	pid_t	pid;
}	t_data;

/*##############################################*/
/*					Commands					*/
/*##############################################*/

void	ft_echo(t_data *data);
void	ft_pwd(void);

#endif
