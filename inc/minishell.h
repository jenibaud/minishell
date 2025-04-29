/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:06:13 by jenibaud          #+#    #+#             */
/*   Updated: 2025/04/29 13:04:39 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct	s_prompt
{
	char	*cmd;
	char	*args;
}	t_prompt;


#endif
